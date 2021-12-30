#include "sys/stat.h"
#include "slibc.h"
#include "sys/syscall.h"

int stat(const char *path, struct stat *buf)
{
	return slibc_syscall_and_set2(SYS_stat, (slibc_u64)path, (slibc_u64)buf);
}
