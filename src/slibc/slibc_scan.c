#include "ctype.h"
#include "slibc.h"
#include "stdarg.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define SCAN_FAILED 0
#define SCAN_OK 1
#define SCAN_NO_PLACEHOLDER 2

static int scan_for_placeholder(slibc_scan_readfn fn, void *fnarg, int *nread, va_list targets)
{
	int result = SCAN_OK;
	int c;
	char cc;
	char *token = NULL;
	char *token_extended;

	// read out character that tells us what we are looking at

	if ((c = fn(fnarg, *nread) == EOF))
	{
		result = SCAN_FAILED;
		goto end;
	}

	*nread += 1;

	// now parse; depending on type this can involve reading the token first

	if (c == '%')
	{
		result = SCAN_NO_PLACEHOLDER;
		goto end;
	}

	if (c == 'c')
	{
		if ((c = fn(fnarg, *nread)) == EOF)
		{
			result = SCAN_FAILED;
			goto end;
		}

		*nread += 1;
		int *const target = va_arg(targets, int *);
		*target = c;
	}

	if (c == 'd')
	{
		if (!(token = strdup("")))
		{
			result = SCAN_FAILED;
			goto end;
		}

		while ((c = fn(fnarg, *nread)) != EOF)
		{
			*nread += 1;

			if (!isdigit(c))
			{
				break;
			}

			cc = (char)c;

			if (!(token_extended = slibc_string_append(token, &cc, sizeof(cc))))
			{
				result = SCAN_FAILED;
				goto end;
			}

			token = token_extended;
		}

		int *const target = va_arg(targets, int *);
		*target = (int)strtoll(token, NULL, 10);
	}

end:
	free(token);
	return result;
}

int slibc_scan(slibc_scan_readfn fn, void *fnarg, const char *format, va_list targets)
{
	// This is a super super super basic implementation that does
	// the bare minimum. As I am writing this I hardly even understand
	// how *scanf works because I almost never use it.

	int nmatched = 0;
	int nread = 0;
	const char *format_pos = format;
	int read_val;

	while (format_pos && ((read_val = fn(fnarg, nread)) != EOF))
	{
		const char fc = *format_pos;
		const char rc = (char)read_val;

		nread += 1;
		format_pos += 1;

		if (fc == '%')
		{
			switch (scan_for_placeholder(fn, fnarg, &nread, targets))
			{
			case SCAN_FAILED:
				goto end;

			case SCAN_OK:
				nmatched += 1;
				break;

			case SCAN_NO_PLACEHOLDER:
			default:
				break;
			}

			continue;
		}

		if (fc != rc)
		{
			return nmatched;
		}
	}

end:
	return nmatched;
}
