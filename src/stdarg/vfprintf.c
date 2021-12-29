#include "errno.h"
#include "slibc.h"
#include "stdarg.h"
#include "stdbool.h"
#include "stdio.h"

static int print_to_file(char c, int nwritten, void *fnarg)
{
	(void)nwritten;
	FILE *const fp = fnarg;

	if (c == 0)
	{
		return 0;
	}

	if (fputc(c, fp) == EOF)
	{
		return errno;
	}

	return 0;
}

int vfprintf(FILE *stream, const char *format, va_list args)
{
	const int result = slibc_format(print_to_file, stream, -1, false, format, args);
	if (result < 0)
	{
		errno = -result;
		return -1;
	}

	return result;
}
