#pragma once

#include <stddef.h>

#define EOF -1
#define PRIx32 "x"

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
 * "Whence" arguments for fseek(3).
 */
#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

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
int sprintf(char *str, const char *format, ...);

/**
 * Formatted output to str of maximum length n.
 */
int snprintf(char *str, size_t n, const char *format, ...);

/**
 * Read formatted input from stdin.
 */
int scanf(const char *format, ...);

/**
 * Read formatted input from file.
 */
int fscanf(FILE *stream, const char *format, ...);

/**
 * Read formatted input from string.
 */
int sscanf(const char *str, const char *format, ...);

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

/**
 * Clear error bit from stream.
 */
void clearerr(FILE *stream);

/**
 * Open file.
 */
FILE *fopen(const char *path, const char *mode);

/**
 * Close file.
 */
int fclose(FILE *fp);

/**
 * Put back one byte to fp.
 */
int ungetc(int c, FILE *fp);

/**
 * Read from file.
 */
size_t fread(void *buf, size_t size, size_t nmemb, FILE *fp);

/**
 * Write to file.
 */
size_t fwrite(const void *buf, size_t size, size_t nmemb, FILE *fp);

/**
 * Create temporary file you can use for writing.
 */
FILE *tmpfile(void);

/**
 * Return file position indicator.
 */
long ftell(FILE *stream);

/**
 * Return underlying file descriptor for fp.
 */
int fileno(FILE *fp);

/**
 * Seek in file
 */
int fseek(FILE *fp, long off, int whence);

/**
 * Seek to beginning of fp.
 */
void rewind(FILE *fp);
