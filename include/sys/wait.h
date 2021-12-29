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
