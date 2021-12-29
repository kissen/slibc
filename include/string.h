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
