#include "slibc.h"

slibc_i64 slibc_syscall_and_set2(slibc_u64 num, slibc_u64 arg0, slibc_u64 arg1)
{
	const slibc_i64 result = slibc_syscall2(num, arg0, arg1);
	return slibc_set_errno_for(result);
}
