#include <getopt.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	bool a = false;
	bool b = false;
	const char *C = NULL;
	const char *D = NULL;

	int c;

	while ((c = getopt(argc, argv, "abc:d:")) != -1)
	{
		switch (c)
		{
		case 'a':
			a = true;
			break;

		case 'b':
			b = true;
			break;

		case 'c':
			C = optarg;
			break;

		case 'd':
			D = optarg;
			break;

		default: {
			fprintf(stderr, "error: got bad c=%c\n", (char)c);
			return 1;
		}
		}
	}

	printf("a=%d b=%d C=%s D=%s\n", (int)a, (int)b, C, D);
	return 0;
}
