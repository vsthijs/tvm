#ifndef TVM_MEM_ALLOC_H
#define TVM_MEM_ALLOC_H 1

#include "../basic.h"

/// functions for managing heap memory, and detecting memory leaks

// initialize the module
void mem_init();

// check for memory leaks
bool mem_deinit(bool quiet);

void *mem_alloc(size_t);
void *mem_realloc(void *, size_t);
void mem_free(void *);

#endif