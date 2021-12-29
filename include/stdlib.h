#pragma once

/**
 * Exit process with status.
 */
void exit(int status);

// (7.22) General utilities

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

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
