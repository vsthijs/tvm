#include "mem/alloc.h"
#include "mem/vector.h"


Vector vec_init(size_t elsz) { return (Vector){0, elsz, 0, NULL}; }

void _vec_resize(Vector *self, size_t);

void vec_deinit(Vector *self) { mem_free(self->base); }

void *vec_get_at(Vector *self, size_t index) {
    if (index < self->length) {
        return self->base[index];
    } else {
        return NULL;
    }
}

void *vec_pop(Vector *self) { return self->base[--self->length]; }

void vec_push(Vector *self, void *value) {
    _vec_resize(self, self->length);
    self->base[self->length++] = value;
}

void _vec_resize(Vector *self, size_t nsize) {
    if (nsize < self->capacity) {
        return;
    } else {
        self->base = mem_realloc(self->base, nsize + 1);
    }
}