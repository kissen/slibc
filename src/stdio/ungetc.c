#include "stdio.h"

#include "stdio/file.h"

int ungetc(int c, FILE *fp)
{
	if (fp->nunget > 0)
	{
		return EOF;
	}

	fp->nunget = 1;
	fp->unget = c;

	return c;
}
