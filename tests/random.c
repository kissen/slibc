#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "%s: need exactly one argument N\n", *argv);
		exit(1);
	}

	const int N = atoi(argv[1]);

	for (int i = 0; i < N; ++i)
	{
		const int choice = random();
		printf("%d\n", choice);
	}

	return 0;
}
