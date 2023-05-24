#include "slibc.h"
#include "stdarg.h"
#include "stdio.h"

static int format_readfn(void *strptr, int nread)
{
	const char *const str = strptr;
	const char c = str[nread];

	return c ? c : EOF;
}

int vsscanf(const char *str, const char *format, va_list ap)
{
	return slibc_scan(format_readfn, (void *)str, format, ap);
}
