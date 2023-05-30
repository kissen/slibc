#include "sys/stat.h"
#include "slibc.h"
#include "sys/syscall.h"

int stat(const char *path, struct stat *buf)
{
	return slibc_syscall_and_set2(SYS_stat, (uint64_t)path, (uint64_t)buf);
}
