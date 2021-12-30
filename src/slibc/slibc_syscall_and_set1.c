#include "slibc.h"

slibc_i64 slibc_syscall_and_set1(slibc_u64 num, slibc_u64 arg0)
{
	const slibc_i64 result = slibc_syscall1(num, arg0);
	return slibc_set_errno_for(result);
}
