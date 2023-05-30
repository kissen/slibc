#include "slibc.h"
#include "sys/syscall.h"
#include "unistd.h"

ssize_t write(int fd, const void *buf, size_t count)
{
	return slibc_syscall_and_set3(SYS_write, fd, (uint64_t)buf, count);
}
