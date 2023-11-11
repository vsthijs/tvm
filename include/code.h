#ifndef TVM_CODE_H
#define TVM_CODE_H 1

#include "basic.h"

typedef struct {
    size_t sz;
    uint8_t *base;
    bool is_alive;
    atomic_bool __lock;
} Buffer;

Buffer buffer_from_file(const char *path);
Buffer buffer_zeros(size_t sz);

void buffer_deinit(Buffer *self);

// Lock the buffer. Returns true when successful.
bool buffer_lock(Buffer *self, bool block);
void buffer_unlock(Buffer *self);

void buffer_resize(Buffer *self, size_t new_sz);

Buffer buffer_concat(Buffer *self, Buffer *other);
void buffer_add(Buffer *self, char byte);
Buffer buffer_copy(Buffer *self);

#endif