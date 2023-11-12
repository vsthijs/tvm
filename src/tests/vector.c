#include "tests/vector.h"
#include "mem/vector.h"

const char *reason;

bool _test_vector_0() {
    unsigned char a = 69;
    unsigned char b = 165;
    unsigned char c, d;
    Vector vec = vec_init(2, 1);

    vec_push(&vec, &a); // 69
    vec_push(&vec, &b); // 420 69
    if (!vec_pop(&vec, &c)) {
        reason = "vec_pop failed (c)";
        return false;
    } else if (!vec_pop(&vec, &d)) {
        reason = "vec_pop failed (d)";
        return false;
    } else if (b != c) {
        reason = "vec_pop returned wrong value (b!=c)";
        return false;
    } else if (a != d) {
        reason = "vec_pop returned wrong value (a!=d)";
        return false;
    } else
        return true;
}