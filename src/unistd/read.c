#include "slibc.h"
#include "sys/syscall.h"
#include "unistd.h"

ssize_t read(int fd, void *buf, size_t count)
{
	return slibc_syscall_and_set3(SYS_read, fd, (slibc_u64)buf, count);
}
