#include "slibc.h"

slibc_i64 slibc_syscall_and_set0(slibc_u64 num)
{
	const slibc_i64 result = slibc_syscall0(num);
	return slibc_set_errno_for(result);
}
