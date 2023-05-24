#include "slibc.h"
#include "string.h"

size_t slibc_string_len(const char *s)
{
	return s ? strlen(s) : 0;
}
