#include <stdio.h>
#include <stdlib.h>

static void fail_with(const char *prefix)
{
	perror(prefix);
	exit(1);
}

int main(void)
{
	static const char *NAME = "/tmp/freadwrite.txt";

	// (1) Open file for writing.

	FILE *const fp = fopen(NAME, "w+");
	if (!fp)
	{
		fail_with("fopen(mode=w)");
	}

	// (2) Write to file.

	const int values[] = {1, 2, 3, 4, 5};

	if (fwrite(values, sizeof(int), 5, fp) != 5)
	{
		fail_with("fwrite");
	}

	// (3) Close file.

	if (fclose(fp) == EOF)
	{
		fail_with("fclose");
	}

	// (4) Re-open file. This time for reading.

	FILE *const rfp = fopen(NAME, "r");
	if (!rfp)
	{
		fail_with("fopen(mode=r)");
	}

	// (5) Read from file.

	int rbuf[5];

	if (fread(rbuf, sizeof(int), 5, fp) != 5)
	{
		fail_with("fwrite");
	}

	// (6) Close file again.

	if (fclose(rfp) == EOF)
	{
		fail_with("fclose");
	}

	// (7) Validate contents.

	for (int i = 0; i < 5; ++i)
	{
		const int wi = values[i];
		const int ri = rbuf[i];
		printf("values[%d] = %d, rbuf[%d] = %d, match=%d\n", i, wi, i, ri, (int)(wi == ri));
	}

	return 0;
}
