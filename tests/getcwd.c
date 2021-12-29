#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc <= 1) {
        fputs("usage: getcwd BUFSIZE\n", stderr);
        exit(EXIT_FAILURE);
    }

    const int bufsize = atoi(argv[1]);

    if (bufsize <= 0) {
        fprintf(stderr, "error: bad bufsize %d\n", bufsize);
        exit(EXIT_FAILURE);
    }

    char *const buf = malloc(bufsize);

    if (!buf) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    if (getcwd(buf, bufsize) == NULL) {
        perror("getcwd");
        return EXIT_FAILURE;
    }

    puts(buf);
    free(buf);

    return EXIT_SUCCESS;
}
