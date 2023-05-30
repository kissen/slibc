#include <slibc.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	uint64_t sum = 0;

	for (int i = 1; i < argc; ++i)
	{
		const uint64_t value = strtoll(argv[i], NULL, 10);
		sum += value;
	}

	const char *const as_string = slibc_u64_to_string(sum);
	puts(as_string);

	return 0;
}
