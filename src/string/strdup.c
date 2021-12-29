#include "stdlib.h"
#include "string.h"

char *strdup(const char *s)
{
    if (!s) {
        return NULL;
    }

    const size_t len = strlen(s);
    char *const buffer = malloc(len);

    if (!buffer) {
        return NULL;
    }

    strcpy(buffer, s);
    return buffer;
}
