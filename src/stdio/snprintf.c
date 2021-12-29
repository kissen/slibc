#include "stdarg.h"
#include "stdio.h"

int snprintf(char *buffer, size_t bufsize, const char *format, ...)
{
    va_list args;
    va_start(args, format);

    const int nprinted = vsnprintf(buffer, bufsize, format, args);
    va_end(args);

    return nprinted;
}
