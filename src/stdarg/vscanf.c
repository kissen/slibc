#include "stdarg.h"
#include "stdio.h"

int vscanf(const char *format, va_list ap)
{
	return vfprintf(stdin, format, ap);
}
