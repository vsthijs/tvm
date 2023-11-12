#ifndef TVM_MEM_VECTOR_H
#define TVM_MEM_VECTOR_H 1

#include "../basic.h"

typedef struct {
    size_t length;
    size_t elsz;
    size_t capacity;
    void *base;
} Vector;

Vector vec_init(size_t cap, size_t sz);
void vec_deinit(Vector *self);

// Get the element at a specific position.
// Returns NULL when index is out of range.
void *vec_get_at(Vector *self, size_t);

// Get the last value, after removing it.
bool vec_pop(Vector *self, void *dst);

// Add a value at the end.
void vec_push(Vector *self, void *);

void vec_fit(Vector *self, size_t);

#endif