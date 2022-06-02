#pragma once

#include "alloca.h"
#include "stddef.h"
#include "stdint.h"

// Types

struct random_data
{
    uint64_t state;
};

// (7.22) General utilities

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

// (7.22.1.2) The atoi, atol and atoll functions

/**
 * Convert nptr to int.
 */
int atoi(const char *nptr);

/**
 * Convert nptr to long.
 */
long int atol(const char *nptr);

/**
 * Convert nptr to long long.
 */
long long int atoll(const char *nptr);

// (7.22.1.4) The strtol, strtoll, strotul and strtoull functions

/**
 * Convert nptr to integer.
 */
long int strtol(const char *nptr, char **endptr, int base);

/**
 * Convert nptr to integer.
 */
long long int strtoll(const char *nptr, char **endptr, int base);

/**
 * Convert nptr to integer.
 */
unsigned long int strtoul(const char *nptr, char **endptr, int base);

/**
 * Convert nptr to integer.
 */
unsigned long long int strtoull(const char *nptr, char **endptr, int base);

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

// (7.22.3.5) The realloc function

/**
 * Reallocate ptr to hold size-many bytes. Returns the new memory location or
 * NULL on error.
 */
void *realloc(void *ptr, size_t size);

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

/**
 * Get environment variable value for key. Return NULL if key was not found.
 */
char *getenv(const char *key);

/**
 * Seed the random number generator.
 */
void srand(unsigned int seed);

/**
 * Seed the random number generator. Identical to a call to srand.
 */
void srandom(unsigned int seed);

/**
 * Return a random number.
 */
int rand(void);

/**
 * Return a random number. Similar to a call to rand, but returns a long rather
 * than an int.
 */
long random(void);

/**
 * Seed random number generator at buf.
 *
 * Returns 0 on success. On error, -1 is returned and errno is set to indicate
 * the kind of error.
 */
int srandom_r(unsigned int seed, struct random_data *buf);

/**
 * Return random number in result.
 *
 * Returns 0 on success. On error, -1 is returned and errno is set to indicate
 * the kind of error.
 */
int random_r(struct random_data *buf, int32_t *result);
