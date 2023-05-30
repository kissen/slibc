#include "slibc.h"
#include "sys/syscall.h"
#include "unistd.h"

int pipe(int fds[2])
{
	int *const ptr = fds;
	return slibc_syscall_and_set1(SYS_pipe, (uint64_t)ptr);
}
