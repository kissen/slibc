#include "slibc.h"
#include "stdbool.h"
#include "stddef.h"

/**
 * Write c with fn. Return the number of written characters on success or
 * a negative errno on error.
 */
static int write_char_with(slibc_format_writefn fn, void *fnarg, char c, int nwritten)
{
	const int result = fn(c, nwritten, fnarg);

	if (result != 0)
	{
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

	while (*s)
	{
		const char c = *s;
		const int result = fn(c, nwritten, fnarg);
		if (result != 0)
		{
			return -result;
		}

		s += 1;
		nwritten += 1;
		written_by_us += 1;
	}

	return written_by_us;
}

int slibc_format(slibc_format_writefn fn, void *fnarg, int bufsize, bool terminate_zero,
				 const char *format, va_list args)
{
	const bool buffer_has_no_limit = (bufsize < 0);

	int result;
	int nwritten = 0;
	const char *fptr = format;

	while (buffer_has_no_limit || nwritten < bufsize)
	{
		// final character in string

		if (*fptr == '\0')
		{
			if (terminate_zero)
			{
				if ((result = write_char_with(fn, fnarg, '\0', nwritten)) > 0)
				{
					nwritten += result;
				}
				else
				{
					return result;
				}
			}

			break; // we are done formatting
		}

		// regular case: just print the lovely character

		if (*fptr != '%')
		{
			if ((result = write_char_with(fn, fnarg, *fptr, nwritten)) > 0)
			{
				nwritten += result;
				fptr += 1;
				continue;
			}

			return result;
		}

		// format cases: here it gets hairy

		fptr += 1;

		// actually it was just an escaped % (percentage sign)

		if (*fptr == '%')
		{
			if ((result = write_char_with(fn, fnarg, *fptr, nwritten)) > 0)
			{
				nwritten += result;
				fptr += 1;
				continue;
			}

			return result;
		}

		// it wasn't, we actually have to do formatting..

		const char *to_print = NULL;

		// check for unsigned prefix

		bool is_unsigned = false;

		if (*fptr == 'u')
		{
			is_unsigned = true;
			fptr += 1;
		}

		// check for digit/integer

		if (*fptr == 'd' || *fptr == 'i')
		{
			if (is_unsigned)
			{
				const unsigned int arg = va_arg(args, unsigned int);
				to_print = slibc_u64_to_string(arg);
			}
			else
			{
				const int arg = va_arg(args, int);
				to_print = slibc_i64_to_string(arg);
			}

			goto print_formatted;
		}

		// check for string

		if (*fptr == 's')
		{
			to_print = va_arg(args, const char *);
			goto print_formatted;
		}

	print_formatted:
		if ((result = write_string_with(fn, fnarg, to_print, nwritten)) > 0)
		{
			nwritten += result;
			fptr += 1;
			continue;
		}

		return result;
	}

	return nwritten;
}
