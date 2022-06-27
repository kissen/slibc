#include <ctype.h>
#include <stdio.h>

typedef int(CONVFUNC)(int);

static void print_mapped(const char *s, CONVFUNC f)
{
	for (const char *ptr = s; *ptr; ++ptr)
	{
		const int c = f(*ptr);
		putchar(c);
	}
}

int main(int argc, char **argv)
{
	for (int i = 0; i < argc; ++i)
	{
		const char *s = argv[i];

		printf("%s:\n", s);
		printf("  tolower: ");
		print_mapped(s, tolower);

		printf("\n  toupper: ");
		print_mapped(s, toupper);

		puts("");
	}

	return 0;
}
