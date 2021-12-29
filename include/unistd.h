#pragma once

#include "slibc.h"
#include "stddef.h"

/**
 * UNIX adds ssize_t because size_t is signed and as such cannot
 * easily return error (-1).
 */
typedef slibc_imax ssize_t;

/**
 * Wrapper for write system call.
 */
ssize_t write(int fd, const void *buf, size_t count);
