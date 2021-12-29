#pragma once

#include "stddef.h"

// Redefine C Compiler types for use with our C library.

typedef __builtin_va_list va_list;
#define va_start(ap, last) __builtin_va_start(ap, last)
#define va_arg(ap, type) __builtin_va_arg(ap, type)
#define va_end(ap) __builtin_va_end(ap)
#define va_copy(dest, src) __builtin_va_copy(dest, src)

// I/O w/ variable arguments.

typedef struct FILE FILE;

int vprintf(const char *format, va_list ap);
int vfprintf(FILE *stream, const char *format, va_list ap);

int vsprintf(char *buffer, const char *format, va_list ap);
int vsnprintf(char *buffer, size_t bufsize, const char *format, va_list ap);
