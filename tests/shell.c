#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static void print_promt(void)
{
    static char buf[4096];

    if (getcwd(buf, sizeof(buf))) {
        printf("%s: ", buf);
    }
}

static char *read_line(void)
{
    static char buf[4096];

    if (fgets(buf, sizeof(buf), stdin)) {
        return buf;
    }

    if (feof(stdin)) {
        exit(0);
    }

    char *const end = strchr(buf, '\n');
    if (end) {
        *end = 0;
    }

    return buf;
}

static void run(char *cmd)
{
    const pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, "%s: error: could not fork process\n", cmd);
        return;
    }

    if (pid == 0) {
        // child

        char *argv[] = {
            cmd, NULL
        };

        execvp(cmd, argv);
        perror("execvp");
        exit(1);
    }

    if (pid > 0) {
        // parent
    }
}

int main(void)
{
    while (true) {
        print_promt();
        char *const line = read_line();
        run(line);
    }

    return 0;
}
