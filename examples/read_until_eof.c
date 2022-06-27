#include <stdio.h>

int main(void)
{
	int c;

	while ((c = fgetc(stdin)) != EOF)
	{
		putchar(c);
	}

	if (ferror(stdin))
	{
		return 1;
	}

	if (!feof(stdin))
	{
		return 2;
	}

	return 0;
}
