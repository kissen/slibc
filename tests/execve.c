#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv, char **envp)
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
    char **program_environment = envp;

    execve(program_name, program_argv, program_environment);

    perror("execve");
    return 1;
}
