#include "errno.h"
#include "stdio.h"
#include "string.h"

static const char *format_unknown_error(int errnum)
{
	static char buf[256];
	sprintf(buf, "unknown error with errno=%d", errnum);

	return buf;
}

static const char *error_to_string(int errnum)
{
	switch (errnum)
	{
	case EPERM:
		return "permission denied";
	case ENOENT:
		return "no such file or directory";
	case ENOMEM:
		return "out of memory";
	case EACCES:
		return "permission denied";
	case EINVAL:
		return "invalid argument";
	case EDOM:
		return "domain eror";
	case ERANGE:
		return "range error";
	case EILSEQ:
		return "EILSEQ";
	case 0:
		return "success (no error)";
	default:
		return format_unknown_error(errnum);
	}
}

char *strerror(int errnum)
{
	return (char *)error_to_string(errnum);
}
