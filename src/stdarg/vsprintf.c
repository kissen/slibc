#include "errno.h"
#include "slibc.h"
#include "stdarg.h"
#include "stdio.h"

static int print_to_string(char c, int nwritten, void *fnarg)
{
    char *const buffer = fnarg;
    buffer[nwritten] = c;

    return 0;
}

int vsprintf(char *buffer, const char *format, va_list args)
{
    const int result = slibc_format(print_to_string, buffer, -1, true, format, args);
    if (result < 0) {
        errno = -result;
        return -1;
    }

    return result;
}
