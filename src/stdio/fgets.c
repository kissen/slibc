#include "stddef.h"
#include "stdio.h"

char *fgets(char *s, int size, FILE *stream)
{
	// loop character by character

	int nread = 0;
	int c;

	while ((nread + 1) < size)
	{
		if ((c = fgetc(stream)) == EOF)
		{
			break;
		}

		s[nread] = (char)c;
		nread += 1;

		if (c == '\n')
		{
			break;
		}
	}

	// on error, just return NULL

	if (nread == 0)
	{
		return NULL;
	}

	// on success, terminate w/ zero and return

	s[nread] = 0;
	return s;
}
