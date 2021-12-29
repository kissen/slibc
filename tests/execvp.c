#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc == 0) {
        exit(1);
    }

    if (argc == 1) {
        fprintf(stderr, "usage: %s PROGRAM\n", *argv);
        exit(1);
    }

    char *const program_name = argv[1];
    char *program_argv[] = { program_name, NULL };

    execvp(program_name, program_argv);

    perror("execvp");
    return 1;
}
