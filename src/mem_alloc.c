#include <stdlib.h>

#include "mem/alloc.h"


void* mem_alloc(size_t sz) {
    return malloc(sz);
}

void* mem_realloc(void* ptr, size_t sz) {
    return realloc(ptr, sz);
}

void mem_free(void *ptr) {
    return free(ptr);
}