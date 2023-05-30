#include "slibc.h"

int64_t slibc_syscall_and_set3(uint64_t num, uint64_t arg0, uint64_t arg1, uint64_t arg2)
{
	const int64_t result = slibc_syscall3(num, arg0, arg1, arg2);
	return slibc_set_errno_for(result);
}
