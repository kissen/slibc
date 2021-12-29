#include "stdarg.h"
#include "stdio.h"

int sprintf(char *buffer, const char *format, ...)
{
    va_list args;
    va_start(args, format);

    const int nprinted = vsprintf(buffer, format, args);
    va_end(args);

    return nprinted;
}
