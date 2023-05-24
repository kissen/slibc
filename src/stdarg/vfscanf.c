#include "slibc.h"
#include "stdarg.h"
#include "stdio.h"

static int format_readfn(void *fileptr, int nread)
{
	(void)nread;
	FILE *const fp = fileptr;
	return fgetc(fp);
}

int vfscanf(FILE *stream, const char *format, va_list ap)
{
	return slibc_scan(format_readfn, (void *)stream, format, ap);
}
