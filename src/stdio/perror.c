#include "errno.h"
#include "stdio.h"
#include "string.h"

void perror(const char *prefix)
{
	const char *error_string = strerror(errno);
	fprintf(stderr, "%s: %s\n", prefix, error_string);
}
