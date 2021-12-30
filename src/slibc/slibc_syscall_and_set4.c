#include "slibc.h"

slibc_i64 slibc_syscall_and_set4(slibc_u64 num, slibc_u64 arg0, slibc_u64 arg1, slibc_u64 arg2,
								 slibc_u64 arg3)
{
	const slibc_i64 result = slibc_syscall4(num, arg0, arg1, arg2, arg3);
	return slibc_set_errno_for(result);
}
