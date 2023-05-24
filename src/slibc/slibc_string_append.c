#include "slibc.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

char *slibc_string_append(char *malloced_string, const char *append, size_t chars_to_append)
{
	const size_t required_size = slibc_string_len(malloced_string) + chars_to_append;
	char *const realloced = realloc(malloced_string, required_size);

	if (!realloced)
	{
		return NULL;
	}

	snprintf(realloced, required_size, "%s%s", realloced, append);
	return malloced_string;
}
