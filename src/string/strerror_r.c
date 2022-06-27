#include "stdio.h"
#include "string.h"

int strerror_r(int errnum, char *buf, size_t buflen)
{
	const char *const error_message = strerror(errnum);
	snprintf(buf, buflen, "%s", error_message);

	return 0;
}
