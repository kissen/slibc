#include "errno.h"
#include "slibc.h"
#include "stdlib.h"
#include "unistd.h"

pid_t fork(void)
{
	const slibc_i64 result = slibc_syscall0(57);

	if (result < 0)
	{
		errno = labs(result);
		return -1;
	}

	return result;
}
