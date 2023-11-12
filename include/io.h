#ifndef TVM_IO_H
#define TVM_IO_H 1

#include <stdio.h>

// fopen
FILE *open_file(const char *FileName, const char *Mode);

// fread
int read_file(void *Buffer, size_t BufferSize, size_t ElementSize,
              size_t ElementCount, FILE *Stream);

#endif // TVM_IO_H