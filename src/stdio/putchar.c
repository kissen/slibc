#include "stdio.h"
#include "unistd.h"

int putchar(int c)
{
    const int fd = 1;
    const char buf = c;

    if (write(fd, &buf, 1) == -1) {
        return EOF;
    }

    return 1;
}
