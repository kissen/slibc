#include "slibc.h"
#include "string.h"
#include "unistd.h"

const char *slibc_u64_to_string(uint64_t k)
{
	// special case zero

	if (k == 0)
	{
		return "0";
	}

	// regular case non-zero

	static char buffer[32];

	uint64_t remaining = k;
	ssize_t i = sizeof(buffer) - 1;

	while (remaining > 0 && i >= 1)
	{
		i -= 1;

		const uint64_t digit = remaining % 10;
		const char asciidigit = digit + '0';

		buffer[i] = asciidigit;
		remaining = remaining / 10;
	}

	return buffer + i;
}
