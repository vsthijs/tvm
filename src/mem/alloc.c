#include <stdlib.h>

#include "log.h"
#include "mem/alloc.h"
#include "mem/vector.h"

bool MEM_INITIALIZED = false;
size_t UNFREED_BLOCKS = 0;

void mem_init() {
    if (!MEM_INITIALIZED) {
        UNFREED_BLOCKS = 0;
        MEM_INITIALIZED = true;
    }
}

bool mem_deinit(bool quiet) {
    if (MEM_INITIALIZED) {
        if (UNFREED_BLOCKS > 0) {
            if (!quiet)
                warn("[memory leak] %zu unfreed blocks!", UNFREED_BLOCKS);
            MEM_INITIALIZED = false;
            return false;
        } else {
            MEM_INITIALIZED = false;
            return true;
        }
    } else {
        if (!quiet)
            warn("mem_deinit was called on memory that was never initialized");
        return true;
    }
}

void *mem_alloc(size_t sz) {
    UNFREED_BLOCKS++;
    return calloc(sz, 1);
}

void *mem_realloc(void *ptr, size_t sz) { return realloc(ptr, sz); }

void mem_free(void *ptr) {
    UNFREED_BLOCKS--;
    return free(ptr);
}