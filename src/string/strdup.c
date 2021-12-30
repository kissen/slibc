#include "stdlib.h"
#include "string.h"

char *strdup(const char *s)
{
	if (!s)
	{
		return NULL;
	}

	const size_t buffer_size = strlen(s) + 1;
	char *const buffer = malloc(buffer_size);

	if (!buffer)
	{
		return NULL;
	}

	strcpy(buffer, s);
	return buffer;
}
