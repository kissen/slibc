#include "errno.h"
#include "stdio.h"
#include "stdlib.h"

static char get_int_at(size_t idx)
{
    return (idx % 1000) + 50000;
}

int main(void)
{
    const size_t nelems = 1024 * 1024;

    int *ptr = calloc(nelems, sizeof(int));
    if (!ptr) {
        exit(errno);
    }

    for (size_t i = 0; i < nelems; ++i) {
        const int elem = ptr[i];
        if (elem != 0) {
            exit(100);
        }
    }

    for (size_t i = 0; i < nelems; ++i) {
        ptr[i] = get_int_at(i);
    }

    for (size_t i = 0; i < nelems; ++i) {
        const char actual = ptr[i];
        const char expected = get_int_at(i);

        if (actual != expected) {
            exit(200);
        }
    }

    free(ptr);

    return 0;
}
