#include "errno.h"
#include "slibc.h"
#include "unistd.h"

#include "unistd/linux.h"

char *getcwd(char *buf, size_t size)
{
	void *const result = (void *)slibc_syscall2(79, (slibc_u64)buf, size);

	if (linux_is_error(result))
	{
		errno = linux_get_error_from(result);
		return NULL;
	}

	return buf;
}
