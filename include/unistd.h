#pragma once

#include "stddef.h"
#include "sys/types.h"

/**
 * UNIX adds ssize_t because size_t is signed and as such cannot
 * easily return error (-1).
 */
typedef long long int ssize_t;

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

/**
 * Fork system call.
 */
pid_t fork(void);

/**
 * Getpid system call. Returns the current PID.
 */
pid_t getpid(void);

/**
 * Get the current working directory. Return NULL on error.
 */
char *getcwd(char *buf, size_t size);
