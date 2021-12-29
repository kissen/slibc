#include "ctype.h"
#include "errno.h"
#include "stdbool.h"
#include "stdlib.h"

#include "stdlib/charval.h"

unsigned long long int strtoull(const char *nptr, char **endptr, int base_as_int)
{
	// check arguments

	if (base_as_int < 0 || base_as_int > 36)
	{
		errno = EINVAL;
		return 0;
	}

	// parse nptr

	const long long int base = base_as_int;
	unsigned long long int accu = 0;
	const char *pos = nptr;

	size_t ndigits = 0;
	bool seen_sign = false;

	while (*pos)
	{
		const char c = *pos;
		pos += 1;

		if (!seen_sign && isspace(c))
		{
			continue;
		}

		if (!seen_sign && c == '+')
		{
			seen_sign = true;
			continue;
		}

		const long long int charval = charval_for(c);
		if (charval >= 0 && charval < base)
		{
			accu = accu * base + charval;
			seen_sign = true;
			ndigits += 1;
			continue;
		}

		break;
	}

	if (ndigits == 0)
	{
		errno = EINVAL;
		return 0;
	}

	if (endptr)
	{
		*endptr = (char *)pos;
	}

	return accu;
}
