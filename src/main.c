#include "all.h"

int main(int argc, char** argv) {
    Vector vec = vec_init(sizeof(int));
    int v0 = 1;
    int v1 = 2;
    vec_push(&vec, &v0);
    vec_push(&vec, &v1);
    int p0 = *(int*)vec_pop(&vec);
    int p1 = *(int*)vec_pop(&vec);
    debug("%d, %d", p0, p1);
}