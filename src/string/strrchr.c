#include "string.h"

char *strrchr(const char *s, int c)
{
	// First move to the end of the string.

	const char *ptr = s;

	while (*ptr)
	{
		ptr += 1;
	}

	// Now look for the character.

	while (ptr >= s)
	{
		if (*ptr == c)
		{
			return (char *)ptr;
		}

		ptr -= 1;
	}

	return NULL;
}
