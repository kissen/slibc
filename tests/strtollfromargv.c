#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc <= 1) {
        fputs("error: missing single argument\n", stderr);
        return -1;
    }

    const long long int parsed = strtoll(argv[1], NULL, 10);
    return parsed;
}
