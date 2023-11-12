#ifdef TVM_TEST

#include "basic.h"
#include <stdio.h>

#include "tests/alloc.h"
#include "tests/vector.h"

typedef struct {
    bool (*fn)();
    const char *name;
} test_t;

const char *reason = "unknown";

test_t all_tests[] = {
    {_test_alloc_0, "memory leak detection"},
    {_test_alloc_1, "incorrect memory leak"},
    {_test_vector_0, "general vector tests"},
};

void test(test_t _test) {
    reason = "unknown";
    printf("[test] running %s... ", _test.name);
    if (_test.fn())
        printf("ok\n");
    else
        printf("failed: %s\n", reason);
}

int main(int argc, char **argv) {
    for (int i = 0; i < sizeof(all_tests) / sizeof(test_t); i++) {
        test(all_tests[i]);
    }
}

#endif