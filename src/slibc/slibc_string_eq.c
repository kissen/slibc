#include "slibc.h"
#include "stdbool.h"
#include "string.h"

bool slibc_string_eq(const char *s, const char *t)
{
	if (!s && !t) {
		return true;
	}

	if (!s || !t) {
		return false;
	}

	return !strcmp(s, t);
}
