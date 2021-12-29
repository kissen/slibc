#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc <= 1)
	{
		fputs("error: missing single argument\n", stderr);
		return -1;
	}

	const int parsed = atoi(argv[1]);
	return parsed;
}
