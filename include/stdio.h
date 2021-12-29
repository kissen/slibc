#pragma once

/**
 * Opaque data type that represents a file handle.
 */
typedef struct FILE FILE;

/**
 * Write least significant byte from c to fp.
 */
int fputc(int c, FILE *fp);

/**
 * Write string s to fp.
 */
int fputs(const char *s, FILE *fp);

/**
 * Write least significant byte from c to fp.
 */
int putc(int c, FILE *fp);

/**
 * Write least significant byte from c to stdout.
 */
int putchar(int c);

/**
 * Write string s to stdout. A newline is appended to stdout.
 */
int puts(const char *s);