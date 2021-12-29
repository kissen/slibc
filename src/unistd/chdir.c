#include "errno.h"
#include "slibc.h"
#include "stdlib.h"
#include "unistd.h"

int chdir(const char *dir)
{
	const slibc_i64 result = slibc_syscall1(80, (slibc_u64)dir);

	if (result < 0)
	{
		errno = labs(result);
		return -1;
	}

	return result;
}
