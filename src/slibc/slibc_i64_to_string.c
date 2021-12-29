#include "slibc.h"
#include "stdlib.h"
#include "string.h"

const char *slibc_i64_to_string(slibc_i64 k)
{
	const slibc_u64 absolute = llabs(k);
	const char *const as_string = slibc_u64_to_string(absolute);

	if (k >= 0)
	{
		return as_string;
	}

	static char buf[32];
	strcpy(buf + 1, as_string);
	buf[0] = '-';

	return buf;
}
