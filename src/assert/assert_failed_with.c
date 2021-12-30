#include "assert.h"
#include "stdio.h"
#include "stdlib.h"

void assert_failed_with(const char *filename, int lineno, const char *function,
						const char *expression)
{
	fprintf(stderr, "%s:%d: %s: assertion \"%s\" failed\n", filename, lineno, function, expression);
	abort();
}
