#include "errno.h"
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

#include "stdio/file.h"

int fgetc(FILE *stream)
{
    ssize_t result;
    char buf;

    if ((result = read(stream->fd, &buf, sizeof(buf))) == -1) {
        errno = labs(result);
        stream->fd |= FILE_FLAGS_ERROR;
        return EOF;
    }

    if (result == 0) {
        stream->flags |= FILE_FLAGS_EOF;
        return EOF;
    }

    return buf;
}
