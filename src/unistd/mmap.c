#include "errno.h"
#include "slibc.h"
#include "sys/syscall.h"
#include "unistd.h"

#include "unistd/linux.h"

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	void *const result = (void *)slibc_syscall6(SYS_mmap, (uint64_t)addr, length, prot, flags, fd, offset);

	if (linux_is_error(result))
	{
		errno = linux_get_error_from(result);
		return MAP_FAILED;
	}

	return (void *)result;
}
