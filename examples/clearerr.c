#include "stdio.h"

#include "stdio/file.h"

int main(void)
{
	if (ferror(stdin))
	{
		return 1;
	}

	stdin->flags |= FILE_FLAGS_ERROR;

	if (!ferror(stdin))
	{
		return 2;
	}

	clearerr(stdin);

	if (ferror(stdin))
	{
		return 3;
	}

	return 0;
}
