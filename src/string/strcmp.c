#include "string.h"

int strcmp(const char *s, const char *t)
{
	while (*s && (*s == *t))
	{
		s += 1;
		t += 1;
	}

	return ((int)*t) - ((int)*s);
}
