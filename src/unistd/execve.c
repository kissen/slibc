#include "errno.h"
#include "slibc.h"
#include "stdlib.h"
#include "unistd.h"

int execve(const char *file, char *const argv[], char *const envp[])
{
	const uint64_t file64 = (uint64_t)file;
	const uint64_t argv64 = (uint64_t)argv;
	const uint64_t envp64 = (uint64_t)envp;

	const int64_t error = slibc_syscall3(59, file64, argv64, envp64);

	errno = labs(error);
	return -1;
}
