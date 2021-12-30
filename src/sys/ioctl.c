#include "sys/ioctl.h"
#include "errno.h"
#include "slibc.h"
#include "stdarg.h"
#include "sys/syscall.h"

#define UNKNOWN_REQUEST_NUMBER -1

static int number_of_arguments_for(unsigned long req)
{
	switch (req)
	{
	case TIOCGWINSZ:
		return 1;

	default:
		return UNKNOWN_REQUEST_NUMBER;
	}
}

int ioctl(int fd, unsigned long req, ...)
{
	const int nargs = number_of_arguments_for(req);
	if (nargs == UNKNOWN_REQUEST_NUMBER)
	{
		errno = EINVAL;
		return -1;
	}

	unsigned long arg = 0;

	if (nargs == 1)
	{
		va_list vargs;
		va_start(vargs, req);
		arg = va_arg(vargs, unsigned long);
		va_end(vargs);
	}

	return slibc_syscall_and_set3(SYS_ioctl, fd, req, arg);
}
