#include "string.h"

void *memset(void *s, int c, size_t n)
{
	const char byte = c;
	char *const bytes = s;

	for (size_t i = 0; i < n; ++i)
	{
		bytes[i] = byte;
	}

	return s;
}
