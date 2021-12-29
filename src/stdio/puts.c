#include "limits.h"
#include "stdio.h"

int puts(const char *s)
{
    int nwritten = 0;

    // Write out s and the terminating \n.

    if ((nwritten = fputs(s, stdout)) == EOF) {
        return EOF;
    }

    if (putchar('\n') == EOF) {
        return EOF;
    }

    // We have to return a non-negative value on success; ideally that is the
    // number of written characters. In theory fputs could have returned
    // INT_MAX, so to avoid overflows we have to check for INT_MAX here.

    if (nwritten == INT_MAX) {
        return INT_MAX;
    }

    return nwritten;
}
