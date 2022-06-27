#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp = NULL;
	static const char example_data[] = "lauf davon, so schnell du kannst";

	if (!(fp = tmpfile()))
	{
		perror("tmpfile");
		exit(1);
	}

	const size_t nmemb = sizeof(example_data) - 1; // skip terminating zero

	if (fwrite(example_data, 1, nmemb, fp) != nmemb)
	{
		perror("fwrite");
		exit(1);
	}

	if (fclose(fp) == EOF)
	{
		perror("fclose");
		exit(1);
	}

	return 0;
}
