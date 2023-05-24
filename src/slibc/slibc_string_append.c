#include "slibc.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

char *slibc_string_append(char *const malloced_string, const char *const append,
						  const size_t chars_to_append)
{
	// enlarge malloced_string to contain the tail

	const size_t required_size = slibc_string_len(malloced_string) + chars_to_append + 1;
	char *const realloced = realloc(malloced_string, required_size);

	if (!realloced)
	{
		return NULL;
	}

	// copy tail

	char *dstptr = realloced;
	const char *srcptr = append;

	while (*dstptr)
	{
		dstptr += 1;
	}

	for (size_t i = 0; i < chars_to_append; ++i)
	{
		*dstptr = *srcptr;
		dstptr += 1;
		srcptr += 1;
	}

	// terminate and return

	*dstptr = 0;

	return realloced;
}
