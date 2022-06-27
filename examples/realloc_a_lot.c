#include <stdlib.h>

static void *xrealloc(void *ptr, size_t n)
{
	void *new_ptr = realloc(ptr, n);
	if (!new_ptr)
	{
		exit(100);
	}

	return new_ptr;
}

int main(void)
{
	const size_t mib = 1024 * 1024;
	void *ptr = NULL;

	for (size_t i = 0; i < mib; ++i)
	{
		ptr = xrealloc(ptr, i);
	}

	return 0;
}
