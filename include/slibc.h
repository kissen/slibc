#pragma once

#include "stdarg.h"
#include "stdbool.h"
#include "stdint.h"
#include "stdio.h"

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
uint64_t slibc_syscall0(uint64_t num);

/**
 * Issue system call num with one argument.
 */
uint64_t slibc_syscall1(uint64_t num, uint64_t);

/**
 * Issue system call num with two arguments.
 */
uint64_t slibc_syscall2(uint64_t num, uint64_t, uint64_t);

/**
 * Issue system call num with three arguments.
 */
uint64_t slibc_syscall3(uint64_t num, uint64_t, uint64_t, uint64_t);

/**
 * Issue system call num with four arguments.
 */
uint64_t slibc_syscall4(uint64_t num, uint64_t, uint64_t, uint64_t, uint64_t);

/**
 * Issue system call num with six arguments.
 */
uint64_t slibc_syscall6(uint64_t num, uint64_t, uint64_t, uint64_t, uint64_t, uint64_t, uint64_t);

/**
 * Handle numeric system call result. If it is negative, errno is set
 * accordingly and -1 is returned. If the result is >= 0, that value is returned
 * as-is and errno is not touched.
 */
int64_t slibc_set_errno_for(int64_t system_call_result);

/**
 * Issue system call with given arguments. Handle the result as by a call to
 * slibc_set_errno_for. Return error code for use by the application.
 */
int64_t slibc_syscall_and_set0(uint64_t num);

/**
 * Issue system call with given arguments. Handle the result as by a call to
 * slibc_set_errno_for. Return error code for use by the application.
 */
int64_t slibc_syscall_and_set1(uint64_t num, uint64_t);

/**
 * Issue system call with given arguments. Handle the result as by a call to
 * slibc_set_errno_for. Return error code for use by the application.
 */
int64_t slibc_syscall_and_set2(uint64_t num, uint64_t, uint64_t);

/**
 * Issue system call with given arguments. Handle the result as by a call to
 * slibc_set_errno_for. Return error code for use by the application.
 */
int64_t slibc_syscall_and_set3(uint64_t num, uint64_t, uint64_t, uint64_t);

/**
 * Issue system call with given arguments. Handle the result as by a call to
 * slibc_set_errno_for. Return error code for use by the application.
 */
int64_t slibc_syscall_and_set4(uint64_t num, uint64_t, uint64_t, uint64_t, uint64_t);

/**
 * Issue system call with given arguments. Handle the result as by a call to
 * slibc_set_errno_for. Return error code for use by the application.
 */
int64_t slibc_syscall_and_set6(uint64_t num, uint64_t, uint64_t, uint64_t, uint64_t, uint64_t,
							   uint64_t);

/**
 * Try to multiply lhs with rhs. Write result to product.
 * Returns ptr on success and NULL on error (overflow). On error,
 * errno is set to ERANGE.
 */
uint64_t *slibc_safe_multiply_u64(uint64_t lhs, uint64_t rhs, uint64_t *product);

/**
 * Convert n to a string representation. The returned string is guaranteed
 * to zero-terminated and statically allocated. Do not pass it to free.
 */
const char *slibc_u64_to_string(uint64_t k);

/**
 * Convert n to a string representation. The returned string is guaranteed
 * to zero-terminated and statically allocated. Do not pass it to free.
 */
const char *slibc_i64_to_string(int64_t k);

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

/**
 * Function type used with function slibc_scan. A call to a function of type
 * slibc_scan_readfn should read one character (that is, one byte) from some kind
 * of input stream and return that. It should return EOF on error.
 */
typedef int(slibc_scan_readfn)(void *fnarg, int nread);

/**
 * Scan some input stream accessed with function fn for format. Write matched
 * arguments into targets.
 *
 * Return the number of matched targets.
 */
int slibc_scan(slibc_scan_readfn fn, void *fnarg, const char *format, va_list targets);
