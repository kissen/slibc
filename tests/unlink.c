#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void do_unlink(const char *path)
{
	if (unlink(path) != 0)
	{
		perror(path);
		exit(1);
	}
}

int main(int argc, char **argv)
{
	for (int i = 1; i < argc; ++i)
	{
		do_unlink(argv[i]);
	}

	return 0;
}
