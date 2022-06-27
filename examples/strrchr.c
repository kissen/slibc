#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	for (int i = 1; i < argc; ++i)
	{
		const char *arg = argv[i];
		printf("%d: %s %s\n", i, strchr(arg, 'a'), strrchr(arg, 'a'));
	}

	return 0;
}
