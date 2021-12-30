#include "slibc.h"
#include "sys/syscall.h"
#include "unistd.h"

int open(const char *path, int flags)
{
	const slibc_u64 mode = 0644;
	return slibc_syscall_and_set3(SYS_open, (slibc_u64)path, flags, mode);
}
