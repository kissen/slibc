#include "stdarg.h"
#include "stdio.h"

int fscanf(FILE *stream, const char *format, ...)
{
	va_list args;
	va_start(args, format);

	const int nmatched = fscanf(stream, format, args);
	va_end(args);

	return nmatched;
}
