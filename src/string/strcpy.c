#include "string.h"

char *strcpy(char *dst, const char *src)
{
    while (*src) {
        *dst = *src;

        dst += 1;
        src += 1;
    }

    return dst;
}
