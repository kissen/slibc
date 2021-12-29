#include "stdlib.h"

unsigned long int strtoul(const char *nptr, char **endptr, int base)
{
	return (unsigned long int)strtoull(nptr, endptr, base);
}
