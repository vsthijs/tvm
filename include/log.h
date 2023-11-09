#ifndef TVM_LOG_H
#define TVM_LOG_H 1

#include "basic.h"
#include <stdio.h>

#define DEBUG 1

#define debug(...) \
    do { if (DEBUG) printf("[debug] " __VA_ARGS__);printf("\n"); } while (0)

#define info(...) printf("[inf] " __VA_ARGS__);printf("\n")
#define err(...) printf("[err] " __VA_ARGS__);printf("\n")
#define fatal(...) do { printf("[fatal] " __VA_ARGS__); printf("\n"); exit(1); } while(0)

#endif