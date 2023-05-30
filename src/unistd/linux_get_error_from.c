#include "slibc.h"
#include "stdlib.h"

#include "unistd/linux.h"

int64_t linux_get_error_from(void *ptr)
{
	return labs((int64_t)ptr);
}
