#include "errno.h"
#include "stdlib.h"

int random_r(struct random_data *buf, int32_t *result)
{
	if (!buf || !result)
	{
		errno = EINVAL;
		return -1;
	}

	// Based on https://git.musl-libc.org/cgit/musl/tree/src/prng/rand.c.
	buf->state = 6364136223846793005ULL * buf->state + 1;
	*result = buf->state;
	return 0;
}
