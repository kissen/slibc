#include <stdio.h>
#include <stdlib.h>

static void fail_with(const char *prefix)
{
	perror(prefix);
	exit(EXIT_FAILURE);
}

static void cat_file_at(const char *path)
{
	FILE *fp;
	int c;

	if ((fp = fopen(path, "r")) == NULL)
	{
		fail_with(path);
	}

	while ((c = fgetc(fp)) != EOF)
	{
		putchar(c);
	}

	if (ferror(fp))
	{
		perror("fgetc");
	}

	if (fclose(fp) == EOF)
	{
		perror("fclose");
	}
}

int main(int argc, char **argv)
{
	for (int i = 1; i < argc; ++i)
	{
		const char *path = argv[i];
		cat_file_at(path);
	}

	return EXIT_SUCCESS;
}
