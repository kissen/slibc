#include "slibc.h"
#include "sys/syscall.h"
#include "unistd.h"

off_t lseek(int fd, off_t offset, int whence)
{
	const slibc_u64 fd64 = (slibc_u64)fd;
	const slibc_u64 off64 = (slibc_u64)offset;
	const slibc_u64 whence64 = (slibc_u64)whence;

	return slibc_syscall_and_set3(SYS_lseek, fd64, off64, whence64);
}
