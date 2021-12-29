#include "stdarg.h"
#include "stdio.h"

int fprintf(FILE *stream, const char *format, ...)
{
	va_list args;
	va_start(args, format);

	const int nprinted = vfprintf(stream, format, args);
	va_end(args);

	return nprinted;
}
