#ifndef TVM_MEM_ALLOC_H
#define TVM_MEM_ALLOC_H 1

#include "../basic.h"

void* mem_alloc(size_t);
void* mem_realloc(void*, size_t);
void mem_free(void*);

#endif