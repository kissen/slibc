#include "limits.h"
#include "stdio.h"

int fputs(const char *s, FILE *fp)
{
	int nwritten = 0;

	for (const char *cur = s; *cur; ++cur)
	{
		const int c = *cur;
		if (fputc(c, fp) == EOF)
		{
			return EOF;
		}

		if (nwritten != INT_MAX)
		{
			nwritten += 1;
		}
	}

	return nwritten;
}
