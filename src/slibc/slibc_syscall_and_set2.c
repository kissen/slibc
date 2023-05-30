#include "slibc.h"

int64_t slibc_syscall_and_set2(uint64_t num, uint64_t arg0, uint64_t arg1)
{
	const int64_t result = slibc_syscall2(num, arg0, arg1);
	return slibc_set_errno_for(result);
}
