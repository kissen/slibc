#include "stdarg.h"
#include "stddef.h"
#include "stdio.h"

#include "stdio/bprintf.h"

static enum bprintf_result print_to_file(char c, size_t nwritten, void *fnarg)
{
    (void) nwritten;
    FILE *const fp = fnarg;

    if (c == 0) {
        return BPRINTF_RESULT_OK;
    }

    if (fputc(c, fp) == EOF) {
        return BPRINTF_RESULT_FAIL;
    }

    return BPRINTF_RESULT_OK;
}

int vfprintf(FILE *stream, const char *format, va_list ap)
{
    return bprintf(print_to_file, stream, NULL, format, ap);
}
