#include "errno.h"
#include "stdio.h"

#include "file.h"

int fileno(FILE *fp)
{
	if (!fp)
	{
		errno = EBADF;
		return -1;
	}

	return fp->fd;
}
