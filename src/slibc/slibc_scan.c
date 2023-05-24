#include "assert.h"
#include "ctype.h"
#include "slibc.h"
#include "stdarg.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define SCAN_FAILED 0
#define SCAN_OK 1

struct fn_reader
{
	slibc_scan_readfn *fn;
	void *fnarg;
	int nread;
	int unget;
};

static void unget_to(struct fn_reader *reader, int c)
{
	assert(reader->unget == EOF);
	reader->unget = c;
}

static int read_from_func(char *dst, struct fn_reader *reader)
{
	// if a value was ungotten, prefer that

	if (reader->unget != EOF)
	{
		*dst = reader->unget;
		reader->unget = EOF;

		return SCAN_OK;
	}

	// we have to actually invoke the callback

	int c;

	if ((c = reader->fn(reader->fnarg, reader->nread)) == EOF)
	{
		return SCAN_FAILED;
	}

	*dst = (char)c;
	reader->nread += 1;

	return SCAN_OK;
}

static int scan_char(int *dst, struct fn_reader *reader)
{
	char c;

	if (read_from_func(&c, reader) == SCAN_FAILED)
	{
		return SCAN_FAILED;
	}

	*dst = c;
	return SCAN_OK;
}

static int scan_digits(int *dst, struct fn_reader *reader)
{
	char c;
	char *token = NULL;
	char *tokennext;

	if (!(token = strdup("")))
	{
		goto fail;
	}

	while (read_from_func(&c, reader) != SCAN_FAILED)
	{
		if (!isdigit(c))
		{
			unget_to(reader, c);
			break;
		}

		if (!(tokennext = slibc_string_append(token, &c, sizeof(c))))
		{
			goto fail;
		}

		token = tokennext;
	}

	*dst = strtoll(token, NULL, 10);
	return SCAN_OK;

fail:
	free(token);
	return SCAN_FAILED;
}

int slibc_scan(slibc_scan_readfn fn, void *fnarg, const char *format, va_list targets)
{
	// This is a super super super basic implementation that does
	// the bare minimum. As I am writing this I hardly even understand
	// how *scanf works because I almost never use it.

	int nmatched = 0;
	const char *format_pos = format;
	char in;

	struct fn_reader reader = {.fn = fn, .fnarg = fnarg, .nread = 0, .unget = EOF};

	while (*format_pos)
	{
		if (*format_pos == '%')
		{
			// some placeholder was found

			format_pos += 1;

			switch (*format_pos)
			{
			case 'c': {
				int *const target = va_arg(targets, int *);
				if (scan_char(target, &reader) == SCAN_FAILED)
				{
					goto end;
				}

				break;
			}

			case 'd': {
				int *const target = va_arg(targets, int *);
				if (scan_digits(target, &reader) == SCAN_FAILED)
				{
					goto end;
				}

				break;

			default:
				goto end;
			}
			}

			nmatched += 1;
		}
		else
		{
			// some normal char was found; match it

			if (read_from_func(&in, &reader) == SCAN_FAILED)
			{
				goto end;
			}

			if (*format_pos != in)
			{
				goto end;
			}
		}

		format_pos += 1;
	}

end:
	return nmatched;
}
