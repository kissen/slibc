#include "errno.h"
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

#include "stdio/file.h"

static int fgetc_from_unget(FILE *stream)
{
	stream->nunget -= 1;
	return stream->unget;
}

static int fgetc_from_fd(FILE *stream)
{
	ssize_t result;
	char buf;

	if ((result = read(stream->fd, &buf, sizeof(buf))) == -1)
	{
		errno = labs(result);
		stream->flags |= FILE_FLAGS_ERROR;
		return EOF;
	}

	if (result == 0)
	{
		stream->flags |= FILE_FLAGS_EOF;
		return EOF;
	}

	stream->position += 1;
	return buf;
}

int fgetc(FILE *stream)
{
	if (stream->nunget > 0)
	{
		return fgetc_from_unget(stream);
	}
	else
	{
		return fgetc_from_fd(stream);
	}
}
