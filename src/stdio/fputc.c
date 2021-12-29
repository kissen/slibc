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
        return EOF;
    }

    return buf;
}
