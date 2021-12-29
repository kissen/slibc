#include "slibc.h"
#include "stdbool.h"

/**
 * Write c with fn. Return the number of written characters on success or
 * a negative errno on error.
 */
static int write_char_with(slibc_format_writefn fn, void *fnarg, char c, int nwritten)
{
    const int result = fn(c, nwritten, fnarg);

    if (result != 0) {
        return -result;
    }

    return 1;
}

/**
 * Write c with fn. Return the number of written characters on success or
 * a negative errno on error.
 */
static int write_string_with(slibc_format_writefn fn, void *fnarg, const char *s, int nwritten)
{
    int written_by_us = 0;

    while (*s) {
        const char c = *s;
        const int result = fn(c, nwritten, fnarg);
        if (result != 0) {
            return -result;
        }

        s += 1;
        nwritten += result;
        written_by_us += result;
    }

    return written_by_us;
}

int slibc_format(slibc_format_writefn fn, void *fnarg, int bufsize, const char *format, va_list args)
{
    const bool buffer_has_no_limit = (bufsize < 0);

    int result;
    int nwritten = 0;
    const char *fptr = format;

    while (buffer_has_no_limit || nwritten < bufsize) {
        // final character in string

        if (*fptr == 0) {
            break;
        }

        // regular case: just print the lovely character

        if (*fptr != '%') {
            if ((result = write_char_with(fn, fnarg, *fptr, nwritten)) > 0) {
                nwritten += result;
                fptr += 1;
                continue;
            }

            return result;
        }

        // format cases: here it gets hairy

        fptr += 1;

        // actually it was just an escaped % (percentage sign)

        if (*fptr == '%') {
            if ((result = write_char_with(fn, fnarg, *fptr, nwritten)) > 0) {
                nwritten += result;
                fptr += 1;
                continue;
            }

            return result;
        }

        // check for unsigned prefix

        bool is_unsigned = false;

        if (*fptr == 'u') {
            is_unsigned = true;
            fptr += 1;
        }

        // check for signed digit/integer

        if (*fptr == 'd' && !is_unsigned) {
            const int arg = va_arg(args, int);
            const char *const ss = slibc_i64_to_string(arg);

            if ((result = write_string_with(fn, fnarg, ss, nwritten)) > 0) {
                nwritten += result;
                fptr += 1;
                continue;
            }

            return result;
        }

        // check for unsigned digit/integer

        if (*fptr == 'd' && is_unsigned) {
            const unsigned int arg = va_arg(args, unsigned int);
            const char *const ss = slibc_u64_to_string(arg);

            if ((result = write_string_with(fn, fnarg, ss, nwritten)) > 0) {
                nwritten += result;
                fptr += 1;
                continue;
            }

            return result;
        }
    }

    return nwritten;
}
