#include "slibc.h"
#include "sys/syscall.h"
#include "unistd.h"

int close(int fd)
{
	return slibc_syscall_and_set1(SYS_close, fd);
}
