#include "errno.h"
#include "slibc.h"
#include "stdlib.h"

int64_t slibc_set_errno_for(int64_t system_call_result)
{
	if (system_call_result < 0)
	{
		errno = labs(system_call_result);
		return -1;
	}

	return system_call_result;
}
