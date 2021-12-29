#pragma once

#include "slibc.h"
#include "stddef.h"

/**
 * UNIX adds ssize_t because size_t is signed and as such cannot
 * easily return error (-1).
 */
typedef slibc_imax ssize_t;

/**
 * Standard Unix file descriptors.
 */
#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

/**
 * Wrapper for write system call.
 */
ssize_t write(int fd, const void *buf, size_t count);
