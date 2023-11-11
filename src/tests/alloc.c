#ifndef TVM_TESTS_ALLOC_H
#define TVM_TESTS_ALLOC_H 1

#include "mem/alloc.h"
#include "tests/alloc.h"

const char *reason;

bool _test_alloc_0() {
    mem_init();
    mem_alloc(8);
    if (mem_deinit(true)) {
        reason = "did not detect memory leak";
        return false;
    } else {
        return true;
    }
}

bool _test_alloc_1() {
    mem_init();
    void *ptr = mem_alloc(8);
    mem_free(ptr);
    if (mem_deinit(true)) {
        return true;
    } else {
        reason = "mem_free did not decrement the leak counter";
        return false;
    }
}

#endif // TVM_TESTS_ALLOC_H