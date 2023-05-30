#include "slibc.h"

int64_t slibc_syscall_and_set0(uint64_t num)
{
	const int64_t result = slibc_syscall0(num);
	return slibc_set_errno_for(result);
}
