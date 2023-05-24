#include "stdarg.h"
#include "stdio.h"

int scanf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	const int nmatched = vscanf(format, args);
	va_end(args);

	return nmatched;
}
