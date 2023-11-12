#include "io.h"
#include <stdio.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

// fopen
FILE *open_file(const char *FileName, const char *Mode) {
    return fopen(FileName, Mode);
}

// fread
int read_file(void *Buffer, size_t BufferSize, size_t ElementSize,
              size_t ElementCount, FILE *Stream) {
    return fread(Buffer, ElementSize, ElementCount, Stream);
}
