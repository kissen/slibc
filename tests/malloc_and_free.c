#include "errno.h"
#include "stdio.h"
#include "stdlib.h"

static char get_char_at(size_t idx)
{
    return (idx % 26) + 'A';
}

int main(void)
{
    const size_t len = 1024 * 1024;

    char *ptr = malloc(len);
    if (!ptr) {
        exit(errno);
    }

    for (size_t i = 0; i < len; ++i) {
        ptr[i] = get_char_at(i);;
    }

    for (size_t i = 0; i < len; ++i) {
        const char actual = ptr[i];
        const char expected = get_char_at(i);

        if (actual != expected) {
            abort();
        }
    }

    free(ptr);
}
