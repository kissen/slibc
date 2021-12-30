#include "stdlib.h"

#include "stdlib/random.h"

long random(void)
{
	// Based on https://git.musl-libc.org/cgit/musl/tree/src/prng/rand.c.
	random_last = 6364136223846793005ULL * random_last + 1;
	return random_last;
}
