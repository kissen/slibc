#include "stddef.h"
#include "stdio.h"

int main()
{
    const char message[] = "hello from slibc!\n";

    for (size_t i = 0; i < sizeof(message); ++i) {
        const char c = message[i];
        putchar(c);
    }
}
