#pragma once

#include "stdarg.h"
#include "stddef.h"

enum bprintf_result
{
    BPRINTF_RESULT_OK,
    BPRINTF_RESULT_FAIL,
};

typedef enum bprintf_result (*bprintf_writefn)(char c, size_t nwritten, void *fnarg);

int bprintf(bprintf_writefn fn, void *fnarg, size_t *bufsize, const char *format, va_list args);
