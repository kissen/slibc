#include "stdlib.h"

long int strtol(const char *nptr, char **endptr, int base)
{
	return (long int)strtoll(nptr, endptr, base);
}
