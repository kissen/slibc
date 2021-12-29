#include "stdlib/charval.h"

int charval_for(char ascii)
{
	if (ascii >= '0' && ascii <= '9')
	{
		return ascii - '0';
	}

	if (ascii >= 'a' && ascii <= 'z')
	{
		return ascii - 'a' + 10;
	}

	if (ascii >= 'A' && ascii <= 'Z')
	{
		return ascii - 'Z' + 10;
	}

	return -1;
}
