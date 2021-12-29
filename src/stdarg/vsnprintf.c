#include "errno.h"
#include "limits.h"
#include "slibc.h"
#include "stdarg.h"
#include "stdio.h"

static int print_to_string(char c, int nwritten, void *fnarg)
{
    char *const buffer = fnarg;
    buffer[nwritten] = c;

    return 0;
}

int vsnprintf(char *buffer, size_t bufsize, const char *format, va_list args)
{
    if (bufsize > INT_MAX) {
        errno = ERANGE;
        return -1;
    }

    const int result = slibc_format(print_to_string, buffer, (int) bufsize, true, format, args);
    if (result < 0) {
        errno = -result;
        return -1;
    }

    return result;
}
