#include "errno.h"
#include "limits.h"
#include "stdio.h"
#include "unistd.h"

#include "stdio/file.h"

static ssize_t do_read_item(char *buf, size_t size, FILE *fp)
{
	size_t idx;

	for (idx = 0; idx < size; ++idx)
	{
		const int read = fgetc(fp);
		if (read == EOF)
		{
			return EOF;
		}

		const char byte = read;
		buf[idx] = byte;
	}

	return idx;
}

size_t fread(void *buf, size_t size, size_t nmemb, FILE *fp)
{
	if (size >= SIZE_MAX || nmemb >= SIZE_MAX)
	{
		errno = EINVAL;
		return 0;
	}

	size_t nitems_read = 0;
	char *bytes = buf;

	while (nitems_read < nmemb)
	{
		const ssize_t bytes_consumed = do_read_item(bytes, size, fp);
		if (bytes_consumed == EOF)
		{
			return nitems_read;
		}

		bytes += bytes_consumed;
		nitems_read += 1;
	}

	return nitems_read;
}
