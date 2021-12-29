#include "slibc.h"
#include "string.h"
#include "unistd.h"

const char *slibc_u64_to_string(slibc_u64 k)
{
    // special case zero

    if (k == 0) {
        return "0";
    }

    // regular case non-zero

    static char buffer[32];

    slibc_u64 remaining = k;
    ssize_t i = sizeof(buffer) - 1;

    while (remaining > 0 && i >= 1) {
        i -= 1;

        const slibc_u64 digit = remaining % 10;
        const char asciidigit = digit + '0';

        buffer[i] = asciidigit;
        remaining = remaining / 10;
    }

    return buffer + i;
}
