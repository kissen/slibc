#include "stdarg.h"
#include "stdio.h"

int printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	const int nprinted = vprintf(format, args);
	va_end(args);

	return nprinted;
}
