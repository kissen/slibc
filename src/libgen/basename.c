#include "libgen.h"
#include "string.h"

#define SEPARATOR '/'

const char *basename(const char *path)
{
	char *const last_slash = strrchr(path, SEPARATOR);

	if (last_slash && strlen(last_slash))
	{
		return last_slash + 1;
	}

	return last_slash;
}
