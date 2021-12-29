#include "errno.h"
#include "slibc.h"
#include "stdlib.h"
#include "string.h"

void *calloc(size_t nmemb, size_t size)
{
    slibc_u64 total_bytes;
    void *ptr;

    if (!slibc_safe_multiply_u64(nmemb, size, &total_bytes)) {
        errno = ENOMEM;
        return NULL;
    }

    if ((ptr = malloc(total_bytes)) == NULL) {
        return NULL;
    }

    memset(ptr, 0x00, total_bytes);
    return ptr;
}
