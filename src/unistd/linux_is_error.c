#include "slibc.h"
#include "stdbool.h"

#include "unistd/linux.h"

// Based on linux kernel 5.14.11, file include/linux/err.h
#define MAX_ERRNO 4095

bool linux_is_error(void *ptr)
{
	const uint64_t kernel_return_value = (uint64_t)ptr;
	const uint64_t max_errno = (uint64_t)(-MAX_ERRNO);

	return kernel_return_value >= max_errno;
}
