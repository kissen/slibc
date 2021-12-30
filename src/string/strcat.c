#include "string.h"

char *strcat(char *str, const char *tail)
{
	// Move ptr to the end of the string.

	char *ptr = str;

	while (*ptr)
	{
		ptr += 1;
	}

	// Now append tail until we have reached the last char of src.

	while (*tail)
	{
		*ptr = *tail;

		ptr += 1;
		tail += 1;
	}

	// Finally we have to add the terminating zero and return.

	*ptr = 0;
	return str;
}
