#pragma once

#define EOF -1

/**
 * Opaque data type that represents a file handle.
 */
typedef struct FILE FILE;

/**
 * FILE object for standard file streams.
 */
extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;

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

/**
 * Formatted output to stdout.
 */
int printf(const char *format, ...);

/**
 * Formatted output to fd.
 */
int fprintf(FILE *stream, const char *format, ...);

/**
 * Formatted output to str of arbitrary length.
 */
int sprintf(char *buffer, const char *format, ...);

/**
 * Output error message according to current errno with prefix.
 */
void perror(const char *prefix);

/**
 * Get at most one byte from stream.
 */
int getc(FILE *stream);

/**
 * Get at most one byte from stream.
 */
int fgetc(FILE *stream);

/**
 * Get at most one byte from stdin.
 */
int getchar(void);

/**
 * Read line from stream.
 */
char *fgets(char *s, int size, FILE *stream);

/**
 * Return whether fd has the EOF bit set.
 */
int feof(FILE *stream);

/**
 * Return whether fd has the error bit set.
 */
int ferror(FILE *stream);

/**
 * Flush contents from stream.
 */
int fflush(FILE *stream);
