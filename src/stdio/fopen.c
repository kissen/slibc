#include "errno.h"
#include "fcntl.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"

#include "stdio/file.h"

#define UNKNOWN_MODE -1

static int mode_to_flags(const char *mode)
{
	if (!strcmp(mode, "r"))
	{
		return O_RDONLY;
	}

	if (!strcmp(mode, "r+"))
	{
		return O_RDWR;
	}

	if (!strcmp(mode, "w"))
	{
		return O_WRONLY | O_TRUNC;
	}

	if (!strcmp(mode, "w+"))
	{
		return O_RDWR | O_CREAT | O_TRUNC;
	}

	if (!strcmp(mode, "a"))
	{
		return O_WRONLY | O_TRUNC;
	}

	if (!strcmp(mode, "a+"))
	{
		return O_RDWR | O_CREAT | O_TRUNC;
	}

	return UNKNOWN_MODE;
}

FILE *fopen(const char *path, const char *mode)
{
	// Convert mode. We do this first to catch errors early.

	const int open_flags = mode_to_flags(mode);
	if (open_flags == UNKNOWN_MODE)
	{
		errno = EINVAL;
		return NULL;
	}

	// Allocate struct.

	FILE *fp = NULL;
	int fd;

	if ((fp = calloc(1, sizeof(*fp))) == NULL)
	{
		goto fail;
	}

	// Issue open system call. Fill struct and return.

	if ((fd = open(path, open_flags)) == -1)
	{
		goto fail;
	}

	fp->fd = fd;
	fp->flags = 0;
	fp->nunget = 0;
	fp->unget = 0x7f; // just something to recognize when debugging

	return fp;

fail:;
	const int error = errno;

	free(fp);

	errno = error;
	return NULL;
}
