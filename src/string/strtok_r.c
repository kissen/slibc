#include "stdbool.h"
#include "string.h"

static bool is_delim(char c, const char *delim)
{
	for (const char *ptr = delim; *ptr; ++ptr)
	{
		if (*ptr == c)
		{
			return true;
		}
	}

	return false;
}

char *strtok_r(char *str, const char *delim, char **last)
{
	// If str != NULL, then we are looking at a new string.

	if (str)
	{
		*last = str;
	}

	// If last == NULL, then we have reached the end of a string, i.e. there are
	// no more tokens to return.

	if (*last == NULL)
	{
		return NULL;
	}

	// The next token begins with start. Note that we have to skip all clustered
	// delimiters.

	char *start = *last;

	while (*start && is_delim(*start, delim))
	{
		start += 1;
	}

	if (*start == 0)
	{
		*last = NULL;
		return NULL;
	}

	// Now we look for the end. The end is either the terminating zero or the
	// next occurence of a delimiter.

	char *end = start;

	while (*end && !is_delim(*end, delim))
	{
		end += 1;
	}

	// If end is also the end of the original string, then this is the last call
	// to strtok_r for that string that returns non-NULL.

	if (*end == 0)
	{
		*last = NULL;
		return start;
	}

	// Character *end is just another delimiter, meaning that the original
	// string might contain another token after the current one.

	*end = 0;
	*last = end + 1;

	return start;
}
