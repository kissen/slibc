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
        return EOF;
    }

    return buf;
}
