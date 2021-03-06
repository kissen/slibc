#include "errno.h"
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

#include "stdio/file.h"

int fclose(FILE *fp)
{
	int error = 0;

	if (!fp)
	{
		return 0;
	}

	if (close(fp->fd) == -1)
	{
		error = errno;
	}

	if (fp->on_close_func)
	{
		fp->on_close_func(fp);
	}

	free(fp);

	if (error)
	{
		errno = error;
		return EOF;
	}

	return 0;
}
