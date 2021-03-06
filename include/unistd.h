#pragma once

#include <getopt.h>
#include <stddef.h>
#include <sys/types.h>

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
#define MAP_FAILED ((void *)-1)

/**
 * Envioronment pointer.
 */
extern char **environ;

/**
 * Wrapper for write system call.
 */
ssize_t write(int fd, const void *buf, size_t count);

/**
 * Wrapper for read system call.
 */
ssize_t read(int fd, void *buf, size_t count);

/**
 * Wrapper for the open system call.
 */
int open(const char *path, int flags);

/**
 * Wrapper for the close system call.
 */
int close(int fd);

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
 * Vfork system call. An optimized version of fork(), though
 * our implementation might not be optimized at all.
 */
pid_t vfork(void);

/**
 * Getpid system call. Returns the current PID.
 */
pid_t getpid(void);

/**
 * Get the current working directory. Return NULL on error.
 */
char *getcwd(char *buf, size_t size);

/**
 * Execute a new program. This is the wrapper around the standard execve system
 * call.
 */
int execve(const char *file, char *const argv[], char *const envp[]);

/**
 * Execute a new program.
 */
int execv(const char *file, char *const argv[]);

/**
 * Execute a new program. Take PATH into account.
 */
int execvp(const char *file, char *const argv[]);

/**
 * Execute a new program. Take PATH into account.
 */
int execvpe(const char *file, char *const argv[], char *const envp[]);

/**
 * Switch to dir.
 */
int chdir(const char *dir);

/**
 * Generic interface for running system calls.
 */
long syscall(long number, ...);

/**
 * Try to delete file at path.
 */
int unlink(const char *pathname);

/**
 * Duplicate fd.
 */
int dup(int fd);

/**
 * Duplicate oldfd into newfd.
 */
int dup2(int oldfd, int newfd);

/**
 * Create a pipe.
 */
int pipe(int fds[2]);

/**
 * Seek file at descriptor fd by offset.
 */
off_t lseek(int fd, off_t offset, int whence);

/**
 * Return whether file descriptor fd points to to a TTY.
 */
int isatty(int fd);
