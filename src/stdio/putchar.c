#include "stdio.h"
#include "unistd.h"

int putchar(int c)
{
    const char buf = c;

    if (write(STDIN_FILENO, &buf, 1) == -1) {
        return EOF;
    }

    return 1;
}
