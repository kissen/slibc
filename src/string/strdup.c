#include "stdlib.h"
#include "string.h"

char *strdup(const char *s)
{
	const size_t buffer_len = strlen(s) + 1;
	char *const buffer = malloc(buffer_len);

	if (!buffer)
	{
		return NULL;
	}

	strcpy(buffer, s);
	return buffer;
}
