#include "stdlib.h"

long long int atoll(const char *nptr)
{
	return strtoll(nptr, NULL, 10);
}
