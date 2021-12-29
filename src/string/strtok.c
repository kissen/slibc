#include "stddef.h"
#include "string.h"

char *strtok(char *str, const char *delim)
{
    static char *last;
    return strtok_r(str, delim, &last);
}
