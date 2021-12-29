#include "errno.h"
#include "slibc.h"
#include "stdlib.h"
#include "unistd.h"

pid_t getpid(void)
{
	const slibc_i64 result = slibc_syscall0(39);

	if (result < 0)
	{
		abort();
	}

	return result;
}
