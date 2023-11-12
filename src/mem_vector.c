#include "mem/alloc.h"
#include "mem/vector.h"
#include <string.h>

Vector vec_init(size_t cap, size_t sz) {
    return (Vector){0, sz, cap, mem_alloc(sz * cap)};
}

void vec_deinit(Vector *self) { mem_free(self->base); }

void *vec_get_at(Vector *self, size_t index) {
    if (index < self->length) {
        return self->base + index;
    } else {
        return NULL;
    }
}

bool vec_pop(Vector *self, void *dst) {
    if (self->length > 0) {
        memcpy(dst, self->base + (--self->length), self->elsz);
        return true;
    } else {
        return false;
    }
}

void vec_push(Vector *self, void *value) {
    vec_fit(self, self->length + 1);
    memcpy((self->base + (self->length++)), value, self->elsz);
}

void vec_fit(Vector *self, size_t cap) {
    if (self->capacity >= cap)
        return;
    else {
        self->base = mem_realloc(self->base, cap);
        self->capacity = cap;
    }
}