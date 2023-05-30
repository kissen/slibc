#include "slibc.h"
#include "sys/syscall.h"
#include "unistd.h"

int open(const char *path, int flags)
{
	const uint64_t mode = 0644;
	return slibc_syscall_and_set3(SYS_open, (uint64_t)path, flags, mode);
}
