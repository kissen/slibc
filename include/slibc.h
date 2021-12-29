#pragma once

typedef long long int slibc_imax;
typedef long long unsigned int slibc_umax;

typedef unsigned char slibc_u8;
typedef signed char slibc_i8;

typedef unsigned short slibc_u16;
typedef signed short slibc_i16;

typedef unsigned int slibc_u32;
typedef signed int slibc_i32;

typedef unsigned long int slibc_u64;
typedef signed long int slibc_i64;

/**
 * Resolve to absolute value of X.
 */
#define SLIBC_ABS(X) ((X) < 0 ? -(X) : (X))

/**
 * Resolve to minimum value of X.
 */
#define SLIBC_MIN(X, Y) ((X) < (Y) ? (X) : (Y))

/**
 * ASM entry point.
 */
void _start(void);

/**
 * C entry point. Called from _start.
 */
void slibc_start(int argc, char **argv);

/**
 * Issue system call num with one argument.
 */
slibc_u64 slibc_syscall1(slibc_u64 num, slibc_u64);

/**
 * Issue system call num with two arguments.
 */
slibc_u64 slibc_syscall2(slibc_u64 num, slibc_u64, slibc_u64);

/**
 * Issue system call num with three arguments.
 */
slibc_u64 slibc_syscall3(slibc_u64 num, slibc_u64, slibc_u64, slibc_u64);

/**
 * Issue system call num with six arguments.
 */
slibc_u64 slibc_syscall6(slibc_u64 num, slibc_u64, slibc_u64, slibc_u64, slibc_u64, slibc_u64, slibc_u64);

/**
 * Try to multiply lhs with rhs. Write result to product.
 * Returns ptr on success and NULL on error (overflow). On error,
 * errno is set to ERANGE.
 */
slibc_u64 *slibc_safe_multiply_u64(slibc_u64 lhs, slibc_u64 rhs, slibc_u64 *product);

/**
 * Convert n to a string representation. The returned string is guaranteed
 * to zero-terminated and statically allocated. Do not pass it to free.
 */
const char *slibc_u64_to_string(slibc_u64 k);
