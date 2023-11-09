#ifndef TVM_LOG_H
#define TVM_LOG_H 1

#include "basic.h"
#include <stdio.h>

#define DEBUG 1

#define debug(...) \
    do { if (DEBUG) printf("[debug] " __VA_ARGS__); } while (0)

#define info(...) printf("[inf] " __VA_ARGS__)
#define err(...) printf("[err] " __VA_ARGS__);
#define fatal(...) do { printf("[fatal] " __VA_ARGS__); exit(1); } while(0)

#endif