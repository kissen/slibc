#include "slibc.h"
#include "sys/syscall.h"
#include "unistd.h"

off_t lseek(int fd, off_t offset, int whence)
{
	const uint64_t fd64 = (uint64_t)fd;
	const uint64_t off64 = (uint64_t)offset;
	const uint64_t whence64 = (uint64_t)whence;

	return slibc_syscall_and_set3(SYS_lseek, fd64, off64, whence64);
}
