#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    for (char **arg = argv + 1; *arg; ++arg) {
        const char *key = *arg;
        const char *value = getenv(key);

        if (value) {
            printf("%s: %s\n", key, value);
        }

        if (!value) {
            printf("%s: not found\n", key);
        }
    }

    printf("%s: looked at %d arguments\n", *argv, argc - 1);

    return 0;
}
