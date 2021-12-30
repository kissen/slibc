#include "ctype.h"

int tolower(int c)
{
	if (isupper(c))
	{
		const int diff = 'a' - 'A';
		return c + diff;
	}

	return c;
}
