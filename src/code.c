#include "code.h"
#include "io.h"
#include "log.h"
#include "mem.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

void _buffer_resize(Buffer *self, size_t new_sz);
Buffer _buffer_copy(Buffer *self);

/// implementations

Buffer buffer_from_file(const char *path) {
    FILE *fd = open_file(path, "rb");
    if (fd == NULL) {
        fatal("could not open file %s.", path);
    }

    fseek(fd, 0, SEEK_END);
    size_t sz = ftell(fd);
    rewind(fd);

    Buffer buff = buffer_zeros(sz);
    read_file(buff.base, sz, 1, sz, fd);
    fclose(fd);
    return buff;
}

Buffer buffer_zeros(size_t sz) {
    return (Buffer){sz, mem_alloc(sz), true, false};
}

void buffer_deinit(Buffer *self) {
    if (buffer_lock(self, true)) {
        mem_free(self->base);
        self->is_alive = false;
    }
}

bool buffer_lock(Buffer *self, bool block) {
    if (block) {
        while (self->__lock)
            ;
        if (self->is_alive) {
            self->__lock = true;
            return true;
        } else {
            return false;
        }
    } else if (self->__lock) {
        return false;
    } else {
        if (self->is_alive)
            return true;
        else
            return false;
    }
}

void buffer_unlock(Buffer *self) {
    if (self->__lock) {
        self->__lock = false;
        return;
    } else {
        fatal("tried to lock a buffer that was already unlocked.");
    }
}

Buffer buffer_concat(Buffer *self, Buffer *other) {
    if (buffer_lock(self, true)) {
        if (buffer_lock(other, true)) {
            if (other->sz == 0) {
                return _buffer_copy(self);
            } else if (self->sz == 0) {
                return _buffer_copy(other);
            } else {
                Buffer new = buffer_zeros(self->sz + other->sz);
                memcpy(new.base, self->base, self->sz);
                memcpy(new.base + self->sz, other->base, other->sz);
                return new;
            }
        } else {
            fatal("[in buffer_concat] could not lock the other buffer");
        }
    } else {
        fatal("[in buffer_concat] could not lock the self buffer");
    }
}

void buffer_add(Buffer *self, char byte) {
    if (buffer_lock(self, true)) {
        _buffer_resize(self, self->sz + 1);
        self->base[self->sz++] = byte;
    } else {
        fatal("[in buffer_add] could not lock the self buffer");
    }
}

Buffer _buffer_copy(Buffer *self) {
    Buffer new = buffer_zeros(self->sz);
    memcpy(new.base, self->base, self->sz);
    return new;
}

Buffer buffer_copy(Buffer *self) {
    if (buffer_lock(self, true)) {
        return _buffer_copy(self);
    } else {
        fatal("[in buffer_copy] could not lock buffer");
    }
}

void _buffer_resize(Buffer *self, size_t new_sz) {
    if (self->sz == new_sz)
        return;
    self->base = (uint8_t *)mem_realloc(self->base, new_sz);
}

void buffer_resize(Buffer *self, size_t new_sz) {
    if (buffer_lock(self, true)) {
        return _buffer_resize(self, new_sz);
    } else {
        fatal("[in buffer_resize] could not lock buffer");
    }
}
