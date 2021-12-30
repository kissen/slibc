#include "slibc.h"

slibc_i64 slibc_syscall_and_set6(slibc_u64 num, slibc_u64 arg0, slibc_u64 arg1, slibc_u64 arg2,
								 slibc_u64 arg3, slibc_u64 arg4, slibc_u64 arg5)
{
	const slibc_i64 result = slibc_syscall6(num, arg0, arg1, arg2, arg3, arg4, arg5);
	return slibc_set_errno_for(result);
}
