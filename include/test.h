#ifndef TVM_TEST_H
#define TVM_TEST_H 1

#include "all.h"
#include "basic.h"

typedef bool (*test_t)();
const char *reason = NULL;

bool test_alloc() {
    mem_init();

    mem_alloc(8);

    if (mem_deinit(true)) {
        reason = "did not detect memory leak";
        return false;
    } else {
        return true;
    }
}

void test(test_t _test, const char *name) {
    printf("[test] running %s... ", name);
    if (test_alloc())
        printf("Ok\n");
    else
        printf("Failed\n");
}

int main(int argc, char **argv) {
    test_t tests[] = {
        test_alloc,
    };
    const char *names[] = {"memory leak detection"};
    for (int i = 0; i < sizeof(tests) / sizeof(test_t); i++) {
        test(tests[i], names[i]);
    }
}

#endif