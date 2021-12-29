#include "stdlib.h"
#include "string.h"
#include "unistd.h"

char *getenv(const char *key)
{
    if (!key) {
        return NULL;
    }

    const size_t keylen = strlen(key);

    if (keylen == 0) {
        return NULL;
    }

    for (char **envptr = environ; *envptr; ++envptr) {
        if (strncmp(*envptr, key, keylen) == 0) {
            // TODO: check whether equal sign is actually present
            return (*envptr + keylen + 1);
        }
    }

    return NULL;
}
