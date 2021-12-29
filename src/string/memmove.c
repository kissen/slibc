#include "slibc.h"
#include "string.h"

static char *move_from_back(char *dst, const char *src, size_t n)
{
	for (slibc_imax i = n - 1; i >= 0; --i)
	{
		dst[i] = src[i];
	}

	return dst;
}

static char *move_overlapping(char *dst, const char *src, size_t n)
{
	char *const dst_last_byte = dst + n - 1;
	const char *const src_last_byte = src + n - 1;

	if (src_last_byte > dst && src_last_byte < dst_last_byte)
	{
		return move_from_back(dst, src, n);
	}

	return memcpy(dst, src, n);
}

void *memmove(void *dst, const void *src, size_t n)
{
	if (n == 0 || dst == src)
	{
		return dst;
	}

	return move_overlapping(dst, src, n);
}
