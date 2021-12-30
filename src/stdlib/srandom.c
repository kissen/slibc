#include "stdlib.h"

#include "stdlib/random.h"

void srandom(unsigned int seed)
{
	random_last = seed - 1;
}
