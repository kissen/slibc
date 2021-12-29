#pragma once

#include <sys/types.h>

/**
 * Send signal sig to process with matching pid.
 */
int kill(pid_t pid, int sig);
