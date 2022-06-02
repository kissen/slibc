#include "errno.h"
#include "stdlib.h"

int srandom_r(unsigned int seed, struct random_data *buf)
{
	if (!buf)
	{
		errno = EINVAL;
		return -1;
	}

	buf->state = seed - 1;
	return 0;
}
