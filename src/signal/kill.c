#include "errno.h"
#include "signal.h"
#include "slibc.h"
#include "stdlib.h"
#include "sys/types.h"

int kill(pid_t pid, int sig)
{
	const slibc_i64 result = slibc_syscall2(62, pid, sig);

	if (result < 0)
	{
		errno = labs(result);
		return -1;
	}

	return 0;
}
