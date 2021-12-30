#include "ctype.h"

int toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		const int diff = 'a' - 'A';
		return c - diff;
	}

	return c;
}
