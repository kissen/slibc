#include "stdarg.h"
#include "stdio.h"

int sscanf(const char *str, const char *format, ...)
{
	va_list args;
	va_start(args, format);

	const int nmatched = vsscanf(str, format, args);
	va_end(args);

	return nmatched;
}
