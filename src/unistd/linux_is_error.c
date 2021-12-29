#include "slibc.h"
#include "stdbool.h"

#include "unistd/linux.h"

// Based on linux kernel 5.14.11, file include/linux/err.h
#define MAX_ERRNO 4095

bool linux_is_error(void *ptr)
{
	const slibc_u64 kernel_return_value = (slibc_u64)ptr;
	const slibc_u64 max_errno = (slibc_u64)(-MAX_ERRNO);

	return kernel_return_value >= max_errno;
}
