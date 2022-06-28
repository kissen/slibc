#include "slibc.h"
#include "sys/syscall.h"
#include "unistd.h"

int dup(int fd)
{
	return slibc_syscall_and_set1(SYS_dup, (slibc_u64)fd);
}
