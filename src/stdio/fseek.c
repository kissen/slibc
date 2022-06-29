#include "errno.h"
#include "stdio.h"
#include "unistd.h"

#include "file.h"

int fseek(FILE *fp, long off, int whence)
{
	long new_offset = 0;

	if (!fp)
	{
		errno = EINVAL;
		return -1;
	}

	if ((new_offset = lseek(fp->fd, off, whence)) == -1)
	{
		return -1;
	}

	fp->position = new_offset;
	return 0;
}
