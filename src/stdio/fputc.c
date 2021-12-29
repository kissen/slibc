#include "stdio.h"
#include "unistd.h"

#include "stdio/file.h"

int fputc(int c, FILE *fp)
{
    const char buf = c;

    if (write(fp->fd, &buf, 1) == -1) {
        // TODO: update errno?
        return EOF;
    }

    return 1;
}
