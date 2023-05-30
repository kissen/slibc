#include "errno.h"
#include "fcntl.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"

#include "stdio/file.h"

#define UNKNOWN_MODE -1

static bool starts_with_flag(const char *flag, const char *modestr)
{
	const size_t flaglen = strlen(flag);
	return !strncmp(modestr, flag, flaglen);
}

static int mode_to_flags(const char *const modestr)
{
	const char *m = modestr;
	int mode = 0;

	while (*m)
	{
		if (starts_with_flag("r+", modestr))
		{
			mode |= O_RDWR;
			m += 2;
		}
		else if (starts_with_flag("r", modestr))
		{
			mode |= O_RDONLY;
			m += 1;
		}
		else if (starts_with_flag("w+", modestr))
		{
			mode |= (O_RDWR | O_CREAT | O_TRUNC);
			m += 2;
		}
		else if (starts_with_flag("w", modestr))
		{
			mode |= (O_WRONLY | O_TRUNC);
			m += 1;
		}
		else if (starts_with_flag("a+", modestr))
		{
			mode |= (O_RDWR | O_CREAT | O_TRUNC);
			m += 2;
		}
		else if (starts_with_flag("a", modestr))
		{
			mode |= (O_WRONLY | O_TRUNC);
			m += 1;
		}
		else
		{
			return UNKNOWN_MODE;
		}
	}

	return mode;
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
