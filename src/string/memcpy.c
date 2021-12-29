#include "string.h"

void *memcpy(void *dst, const void *src, size_t n)
{
	char *dstbytes = dst;
	const char *srcbytes = src;

	for (size_t i = 0; i < n; ++i)
	{
		dstbytes[i] = srcbytes[i];
	}

	return dst;
}
