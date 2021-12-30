#include <stdio.h>
#include <string.h>

int main(void)
{
	const int nstrings = 9;

	const char *strings[] = {"abc", "def", "ghi", "jkl", "mno", "pqr", "stu", "vwx", "yz"};

	static char buf[4096];

	for (int i = 0; i < nstrings; ++i)
	{
		printf("%d: %s\n", i, strcat(buf, strings[i]));
	}

	return 0;
}
