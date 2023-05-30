#include "slibc.h"

int64_t slibc_syscall_and_set1(uint64_t num, uint64_t arg0)
{
	const int64_t result = slibc_syscall1(num, arg0);
	return slibc_set_errno_for(result);
}
