#ifndef TVM_LOG_H
#define TVM_LOG_H 1

#include "basic.h"
#include <stdio.h>

#define DEBUG 1

#define debug(...)                                                             \
    do {                                                                       \
        if (DEBUG)                                                             \
            printf("[debug] " __VA_ARGS__);                                    \
        printf("\n");                                                          \
    } while (0)

#define info(...)                                                              \
    do {                                                                       \
        printf("[inf] " __VA_ARGS__);                                          \
        printf("\n");                                                          \
    } while (0)
#define err(...)                                                               \
    do {                                                                       \
        printf("[err] " __VA_ARGS__);                                          \
        printf("\n");                                                          \
    } while (0)
#define fatal(...)                                                             \
    do {                                                                       \
        printf("[fatal] " __VA_ARGS__);                                        \
        printf("\n");                                                          \
        exit(1);                                                               \
    } while (0)

#define warn(...)                                                              \
    do {                                                                       \
        printf("[warn] " __VA_ARGS__);                                         \
        printf("\n");                                                          \
    } while (0)

#endif