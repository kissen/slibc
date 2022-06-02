#include "stdlib.h"

#include "slibc_global_rng.h"

long random(void)
{
	int32_t random_value;

	if (!random_r(&slibc_global_rng, &random_value))
	{
		return random_value;
	}

	return 0;
}
