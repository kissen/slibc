#pragma once

#include <unistd.h>

struct rusage;

/**
 * Wrapper around the wait4 system call.
 */
pid_t wait4(pid_t pid, int *wstatus, int options, struct rusage *ru);

/**
 * Wait for given pid.
 */
pid_t waitpid(pid_t pid, int *status, int options);

/**
 * Return the exist code from status.
 */
#define WEXITSTATUS(status) (((status) >> 8) & 0xff)

/**
 * Return signal that caused an exit.
 */
#define WTERMSIG(status) ((status)&0x7f)

/**
 * Return signal that caused stop.
 */
#define WSTOPSIG(status) (WEXITSTATUS(status))

/**
 * Return whether child terminated normally.
 */
#define WIFEXITED(status) (!WTERMSIG(status))

/**
 * Return whether child terminated because of a signal.
 */
#define WIFSIGNALED(status) (0)

/**
 * Return whether child stopped because of a signal.
 */
#define WIFSTOPPED(status) (0)
