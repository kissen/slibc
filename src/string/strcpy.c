#include "string.h"

char *strcpy(char *dst, const char *src)
{
    char *const return_value = dst;

    while (*src) {
        *dst = *src;

        dst += 1;
        src += 1;
    }

    return return_value;
}
