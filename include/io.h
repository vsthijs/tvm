#ifndef TVM_IO_H
#define TVM_IO_H 1

#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>

#ifdef __STDC_LIB_EXT1__

// fopen_s
FILE *open_file(const char *FileName, const char *Mode) {
    FILE *fd;
    fopen_s(&fd, FileName, Mode);
}

// fread_s
int read_file(void *Buffer, size_t BufferSize, size_t ElementSize,
              size_t ElementCount, FILE *Stream) {
    return fread_s(Buffer, BufferSize, ElementSize, ElementCount, Stream);
}

#else

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

#pragma GCC diagnostic pop

#endif // __STDC_LIB_EXT1__

#endif // TVM_IO_H