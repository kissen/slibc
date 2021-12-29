#include "errno.h"
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

#include "stdio/file.h"

int fputc(int c, FILE *fp)
{
    ssize_t result;
    const char buf = c;

    if ((result = write(fp->fd, &buf, sizeof(buf))) == -1) {
        errno = labs(result);
        fp->fd |= FILE_FLAGS_ERROR;
        return EOF;
    }

    if (result == 0) {
        fp->fd |= FILE_FLAGS_EOF;
        return EOF;
    }

    return buf;
}
