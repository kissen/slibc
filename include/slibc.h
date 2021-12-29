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
 * Entry points for a lot of compilers.
 */
void _start(void);

/**
 * Issue system call num with one argument.
 */
slibc_u64 slibc_syscall1(slibc_u64 num, slibc_u64 arg0);

/**
 * Issue system call num with two arguments.
 */
slibc_u64 slibc_syscall2(slibc_u64 num, slibc_u64 arg0, slibc_u64 arg1);

/**
 * Issue system call num with three arguments.
 */
slibc_u64 slibc_syscall3(slibc_u64 num, slibc_u64 arg0, slibc_u64 arg2, slibc_u64 arg3);
