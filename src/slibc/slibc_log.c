#include "libgen.h"
#include "slibc.h"
#include "stdarg.h"
#include "stdio.h"

void slibc_log(const char *file, int line, const char *format, ...)
{
	// print header

	const char *const name = basename(file);
	fprintf(stderr, "%s:%d: ", name, line);

	// print message

	va_list args;
	va_start(args, format);

	vfprintf(stderr, format, args);
	va_end(args);

	// print terminator

	fprintf(stderr, "\n");
}
