#pragma once

#include "slibc.h"
#include "stddef.h"

/**
 * UNIX adds ssize_t because size_t is signed and as such cannot
 * easily return error (-1).
 */
typedef slibc_imax ssize_t;

// TODO: move to sys/types?
typedef slibc_imax off_t;

/**
 * Standard Unix file descriptors.
 */
#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

/**
 * Error values.
 */
#define MAP_FAILED ((void *) -1)

/**
 * Wrapper for write system call.
 */
ssize_t write(int fd, const void *buf, size_t count);

/**
 * Wrapper for read system call.
 */
ssize_t read(int fd, void *buf, size_t count);

/**
 * Wrapper for mmap system call.
 */
void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);

/**
 * Wrapper around munmap system call.
 */
int munmap(void *addr, size_t length);
