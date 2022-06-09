#include <stdio.h>

static void tell_size(const char *const filename)
{
	FILE *fp = NULL;
	long size;

	if (!(fp = fopen(filename, "r")))
	{
		perror("fopen");
		goto end;
	}

	while (fgetc(fp) != EOF)
	{
		// fast forward!
	}

	if (ferror(fp))
	{
		perror("fgetc");
		goto end;
	}

	if ((size = ftell(fp)) == -1)
	{
		perror("ftell");
		goto end;
	}

	printf("%s: %d\n", filename, (int)size);

end:
	fclose(fp);
}

int main(int argc, char **argv)
{
	for (int i = 1; i < argc; ++i)
	{
		tell_size(argv[i]);
	}

	return 0;
}
