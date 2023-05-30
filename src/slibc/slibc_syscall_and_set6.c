#include "slibc.h"

int64_t slibc_syscall_and_set6(uint64_t num, uint64_t arg0, uint64_t arg1, uint64_t arg2,
							   uint64_t arg3, uint64_t arg4, uint64_t arg5)
{
	const int64_t result = slibc_syscall6(num, arg0, arg1, arg2, arg3, arg4, arg5);
	return slibc_set_errno_for(result);
}
