#include "slibc.h"
#include "stdbool.h"

#include "stdio/bprintf.h"

// This file is very scary. I recommend not reading it. Instead why not take a
// walk or have some coffee with your friends?

static enum bprintf_result output_char(bprintf_writefn outfunc, void *fnarg, size_t *nwritten, const char **fptr)
{
    if (outfunc(**fptr, *nwritten, fnarg) == BPRINTF_RESULT_FAIL) {
        return BPRINTF_RESULT_FAIL;
    }

    *nwritten += 1;
    *fptr += 1;

    return BPRINTF_RESULT_OK;
}

#define OUTPUT_CHAR_AND_LOOP(outfunc, fnarg, nwritten, fptr) if (output_char(outfunc, fnarg, &nwritten, &fptr) == BPRINTF_RESULT_FAIL) { break; } else { continue; }

static enum bprintf_result output_string(bprintf_writefn outfunc, void *fnarg, size_t *nwritten, const char *const s)
{
    const char *ptr = s;

    while (*ptr) {
        if (outfunc(*ptr, *nwritten, fnarg) == BPRINTF_RESULT_FAIL) {
            return BPRINTF_RESULT_FAIL;
        }

        *nwritten += 1;
        ptr += 1;
    }

    return BPRINTF_RESULT_OK;
}

#define OUTPUT_STRING_AND_LOOP(outfunc, fnarg, nwritten, str) if (output_string(outfunc, fnarg, &nwritten, str) == BPRINTF_RESULT_FAIL) { break; } else { continue; };

int bprintf(bprintf_writefn outfunc, void *fnarg, size_t *const bufsize, const char *const format, va_list args)
{
    size_t nwritten = 0;
    const char *fptr = format;

    while (!bufsize || nwritten < *bufsize) {
        // final character in string

        if (*fptr == 0) {
            break;
        }

        // regular case: just print the lovely character

        if (*fptr != '%') {
            OUTPUT_CHAR_AND_LOOP(outfunc, fnarg, nwritten, fptr);
        }

        // format case: here it gets hairy

        fptr += 1;

        if (*fptr == '%') {
            OUTPUT_CHAR_AND_LOOP(outfunc, fnarg, nwritten, fptr);
        }

        bool is_unsigned = false;

        if (*fptr == 'u') {
            is_unsigned = true;
            fptr += 1;
        }

        if (*fptr == 'd' && !is_unsigned) {
            const int arg = va_arg(args, int);
            fptr += 1;
            OUTPUT_STRING_AND_LOOP(outfunc, fnarg, nwritten, slibc_i64_to_string(arg));
        }

        if (*fptr == 'd' && is_unsigned) {
            const unsigned int arg = va_arg(args, unsigned int);
            fptr += 1;
            OUTPUT_STRING_AND_LOOP(outfunc, fnarg, nwritten, slibc_u64_to_string(arg));
        }
    }

    return nwritten;
}
