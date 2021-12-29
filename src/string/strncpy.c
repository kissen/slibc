#include "string.h"

char *strncpy(char *dst, const char *src, size_t n)
{
	char *const return_value = dst;
	size_t i = 0;

	while (i < n && *src)
	{
		*dst = *src;

		dst += 1;
		src += 1;
		i += 1;
	}

	while (i < n)
	{
		*dst = 0;
		dst += 1;
		i += 1;
	}

	return return_value;
}
