#include "errno.h"
#include "limits.h"
#include "stdio.h"
#include "unistd.h"

#include "stdio/file.h"

static ssize_t do_write_item(const char *buf, size_t size, FILE *fp)
{
	size_t idx;

	for (idx = 0; idx < size; ++idx)
	{
		const char to_write = buf[idx];
		if (fputc(to_write, fp) == EOF)
		{
			return EOF;
		}
	}

	return idx;
}

size_t fwrite(const void *buf, size_t size, size_t nmemb, FILE *fp)
{
	if (size >= SIZE_MAX || nmemb >= SIZE_MAX)
	{
		errno = EINVAL;
		return 0;
	}

	size_t nitems_written = 0;
	const char *bytes = buf;

	while (nitems_written < nmemb)
	{
		const ssize_t bytes_written = do_write_item(bytes, size, fp);
		if (bytes_written == EOF)
		{
			return nitems_written;
		}

		bytes += bytes_written;
		nitems_written += 1;
	}

	return nitems_written;
}
