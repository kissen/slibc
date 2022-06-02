#include "stdlib.h"

#include "slibc_global_rng.h"

void srandom(unsigned int seed)
{
	srandom_r(seed, &slibc_global_rng);
}
