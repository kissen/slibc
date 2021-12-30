#include "slibc.h"

slibc_i64 slibc_syscall_and_set3(slibc_u64 num, slibc_u64 arg0, slibc_u64 arg1, slibc_u64 arg2)
{
	const slibc_i64 result = slibc_syscall3(num, arg0, arg1, arg2);
	return slibc_set_errno_for(result);
}
