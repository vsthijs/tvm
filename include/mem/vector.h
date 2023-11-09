#ifndef TVM_MEM_VECTOR_H
#define TVM_MEM_VECTOR_H 1

#include "../basic.h"

typedef struct {
    size_t length;
    size_t elsz;
    size_t capacity;
    void** base;
} Vector;

Vector vec_init(size_t elsz);
void vec_deinit(Vector* self);

// Get the element at a specific position.
// Returns NULL when index is out of range.
void* vec_get_at(Vector* self, size_t);

// Set the element at a specific position.
void vec_set_at(Vector* self, size_t, void*);
void* vec_pop(Vector* self);
void vec_push(Vector* self, void*);

#endif