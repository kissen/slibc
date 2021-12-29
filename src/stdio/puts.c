#include "stdio.h"

int puts(const char *s)
{
    int nwritten = 0;

    if ((nwritten = fputs(s, stdout)) == EOF) {
        return EOF;
    }

    if (putchar('\n') == EOF) {
        return EOF;
    }

    return nwritten + 1;
}
