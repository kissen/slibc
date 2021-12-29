#pragma once

#include "stddef.h"

// (7.22) General utilities

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

// (7.22.3.3) The free function

/**
 * Free allocated memory at ptr.
 */
void free(void *ptr);

// (7.22.3.2) The calloc function

/**
 * Allocate memory for nmemb-many elements of size bytes.
 * The returned memory is zeroed. Returns NULL on errors.
 */
void *calloc(size_t nmemb, size_t size);

// (7.22.3.4) The malloc function

/**
 * Allocate size-many bytes. Returns NULL on errors.
 */
void *malloc(size_t size);

// (7.22.6.1) The abs, labs, and llabs Functions

/**
 * Return absolute value of k.
 */
int abs(int k);

/**
 * Return absolute value of k.
 */
long labs(long k);

/**
 * Return absolute value of k.
 */
long long llabs(long long k);

// (???) Unsorted

/**
 * Exit process with status.
 */
void exit(int status);

/**
 * Abort the process.
 */
void abort(void);
