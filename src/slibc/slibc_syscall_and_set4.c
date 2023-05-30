#include "slibc.h"

int64_t slibc_syscall_and_set4(uint64_t num, uint64_t arg0, uint64_t arg1, uint64_t arg2,
							   uint64_t arg3)
{
	const int64_t result = slibc_syscall4(num, arg0, arg1, arg2, arg3);
	return slibc_set_errno_for(result);
}
