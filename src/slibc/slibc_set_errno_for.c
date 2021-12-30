#include "errno.h"
#include "slibc.h"
#include "stdlib.h"

slibc_i64 slibc_set_errno_for(slibc_i64 system_call_result)
{
	if (system_call_result < 0)
	{
		errno = labs(system_call_result);
		return -1;
	}

	return system_call_result;
}
