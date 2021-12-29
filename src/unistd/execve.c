#include "errno.h"
#include "slibc.h"
#include "stdlib.h"
#include "unistd.h"

int execve(const char *file, char *const argv[], char *const envp[])
{
	const slibc_u64 file64 = (slibc_u64)file;
	const slibc_u64 argv64 = (slibc_u64)argv;
	const slibc_u64 envp64 = (slibc_u64)envp;

	const slibc_i64 error = slibc_syscall3(59, file64, argv64, envp64);

	errno = labs(error);
	return -1;
}
