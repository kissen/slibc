#pragma once

#include "stdarg.h"
#include "stdbool.h"

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
 * Write formatted log message to stderr. Useful for debugging.
 */
#define SLIBC_LOG(...) slibc_log(__FILE__, __LINE__, __VA_ARGS__);

/**
 * ASM entry point.
 */
void _start(void);

/**
 * C entry point. Called from _start.
 */
void slibc_start(int argc, char **argv);

/**
 * Issue system call num with no arguments.
 */
slibc_u64 slibc_syscall0(slibc_u64 num);

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
 * Issue system call num with four arguments.
 */
slibc_u64 slibc_syscall4(slibc_u64 num, slibc_u64, slibc_u64, slibc_u64, slibc_u64);

/**
 * Issue system call num with six arguments.
 */
slibc_u64 slibc_syscall6(slibc_u64 num, slibc_u64, slibc_u64, slibc_u64, slibc_u64, slibc_u64,
						 slibc_u64);

/**
 * Handle numeric system call result. If it is negative, errno is set
 * accordingly and -1 is returned. If the result is >= 0, that value is returned
 * as-is and errno is not touched.
 */
slibc_i64 slibc_set_errno_for(slibc_i64 system_call_result);

/**
 * Issue system call with given arguments. Handle the result as by a call to
 * slibc_set_errno_for. Return error code for use by the application.
 */
slibc_i64 slibc_syscall_and_set0(slibc_u64 num);

/**
 * Issue system call with given arguments. Handle the result as by a call to
 * slibc_set_errno_for. Return error code for use by the application.
 */
slibc_i64 slibc_syscall_and_set1(slibc_u64 num, slibc_u64);

/**
 * Issue system call with given arguments. Handle the result as by a call to
 * slibc_set_errno_for. Return error code for use by the application.
 */
slibc_i64 slibc_syscall_and_set2(slibc_u64 num, slibc_u64, slibc_u64);

/**
 * Issue system call with given arguments. Handle the result as by a call to
 * slibc_set_errno_for. Return error code for use by the application.
 */
slibc_i64 slibc_syscall_and_set3(slibc_u64 num, slibc_u64, slibc_u64, slibc_u64);

/**
 * Issue system call with given arguments. Handle the result as by a call to
 * slibc_set_errno_for. Return error code for use by the application.
 */
slibc_i64 slibc_syscall_and_set4(slibc_u64 num, slibc_u64, slibc_u64, slibc_u64, slibc_u64);

/**
 * Issue system call with given arguments. Handle the result as by a call to
 * slibc_set_errno_for. Return error code for use by the application.
 */
slibc_i64 slibc_syscall_and_set6(slibc_u64 num, slibc_u64, slibc_u64, slibc_u64, slibc_u64,
								 slibc_u64, slibc_u64);

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

/**
 * Convert n to a string representation. The returned string is guaranteed
 * to zero-terminated and statically allocated. Do not pass it to free.
 */
const char *slibc_i64_to_string(slibc_i64 k);

/**
 * Return length of zero terminated string s in bytes, not including the
 * terminating zero. Unlike strlen(3), this function will return a size
 * of zero if argument s is NULL.
 */
size_t slibc_string_len(const char *s);

/**
 * Take malloced_string and append up to chars_to_append many characters from
 * zero terminated string append to malloced_string. This involves a realloc.
 *
 * Return realloced version of malloced_string with created appendix. Return
 * NULL on allocation errors in which case errno will be set.
 */
char *slibc_string_append(char *malloced_string, const char *append, size_t chars_to_append);

/**
 * Log formatted log message to stderr. Useful for debugging. Instead of calling
 * this function directly, consdere using SLIBC_LOG instead. It already fills out
 * some parameters for you.
 */
void slibc_log(const char *file, int line, const char *format, ...);

/**
 * Function type used with function slibc_format. A call to a function of type
 * slibc_format_writefn should write character c to some output stream when so
 * far nwritten many bytes were written. fnarg is an optional argument
 * implementation-defined by the given implementation.
 *
 * Returns 0 on success and some errno on error.
 */
typedef int(slibc_format_writefn)(char c, int nwritten, void *fnarg);

/**
 * Interpret format as a format string with argument args. Format that output
 * using function fn with fnarg as optional funtion parameter. Write up to bufsize
 * many elements.
 *
 * fnarg is interepreted by fn. busize may be set to a negative value in which case
 * the output stream is assumed to have no limit (e.g. when writing to stdout).
 * If terminate_zero is set to true, a terminating \0 is written using fn at the end.
 *
 * Returns the number of printed characters on success and (-1) * errno on error.
 */
int slibc_format(slibc_format_writefn fn, void *fnarg, int bufsize, bool terminate_zero,
				 const char *format, va_list args);

typedef int(slibc_scan_readfn)(void *fnarg, int nread);
int slibc_scan(slibc_scan_readfn fn, void *fnarg, const char *format, va_list targets);
