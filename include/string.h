#pragma once

#include "stddef.h"

// (7.24) String Handling

// (7.24.2) Copying Functions

/**
 * Copy n bytes from src to dst. The first n bytes of src and dst may not
 * overlap.
 */
void *memcpy(void *dst, const void *src, size_t n);

/**
 * Copy n bytes from src to dst. The first n byte of src and dst may overlap.
 */
void *memmove(void *dst, const void *src, size_t n);

/**
 * Copy zero-terminated string src to dst.
 */
char *strcpy(char *dst, const char *src);

/**
 * Copy zero-terminated string src to dst. Only copy up to n characters.  If src
 * is shorter than n characters, padding null characters are added to dst.
 *
 * strncpy does not gurantee that the string written to dst will be
 * zero-terminated.
 */
char *strncpy(char *dst, const char *src, size_t n);

// (7.24.6.1) The memset function

/**
 * Set the first n bytes in s to the least significant byte in c.
 */
void *memset(void *s, int c, size_t n);

// (???) Unsorted

/**
 * Return statically allocated string that describes errnum.
 */
char *strerror(int errnum);

/**
 * Write string error into buf of bufsize bytes.
 */
int strerror_r(int errnum, char *buf, size_t bufsize);

/**
 * Return lenght of s.
 */
size_t strlen(const char *s);

/**
 * Return first occurence of c in s.
 */
char *strchr(const char *s, int c);

/**
 * Return last occurence of c in s.
 */
char *strrchr(const char *s, int c);

/**
 * Compare two strings for equality.
 */
int strcmp(const char *s, const char *t);

/**
 * Like strcmp, but compares only at most n characters.
 */
int strncmp(const char *s, const char *t, size_t n);

/**
 * Copy contents of s into freshly malloc'd memory.
 */
char *strdup(const char *s);

/**
 * Tokenize strings. Uses scary global state.
 */
char *strtok(char *str, const char *delim);

/**
 * Tokenize strings.
 */
char *strtok_r(char *str, const char *delim, char **last);

/**
 * Append tail to str.
 */
char *strcat(char *str, const char *tail);
