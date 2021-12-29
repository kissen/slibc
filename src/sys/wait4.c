#include "errno.h"
#include "slibc.h"
#include "stdlib.h"
#include "sys/wait.h"

pid_t wait4(pid_t pid, int *wstatus, int options, struct rusage *ru)
{
	const slibc_u64 wstatus64 = (slibc_u64)wstatus;
	const slibc_u64 ru64 = (slibc_u64)ru;

	const slibc_i64 result = slibc_syscall4(61, pid, wstatus64, options, ru64);

	if (result < 0)
	{
		errno = labs(result);
		return -1;
	}

	return result;
}
