#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
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
        char *const end = strchr(buf, '\n');
        if (end) {
            *end = 0;
        }

        return buf;
    }

    if (feof(stdin)) {
        exit(0);
    }

    return buf;
}

static void exec(const char *cmd, char **argv)
{
    const pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, "%s: error: could not fork process\n", cmd);
        return;
    }

    if (pid == 0) {
        execvp(cmd, argv);
        perror(cmd);
        exit(1);
    }

    if (pid > 0) {
        int status;
        if (waitpid(pid, &status, 0) == -1) {
            perror("waitpid");
        }
    }
}

static void run(char *cmdline)
{
    static const char delim[] = " \t\n";

    int argc = 0;
    char **argv = NULL;

    char *token = strtok(cmdline, delim);

    while (token) {
        char **const extended = realloc(argv, (argc + 1) * sizeof(*argv));
        if (!extended) {
            goto cleanup;
        }

        argv = extended;
        argv[argc] = token;
        argc += 1;

        token = strtok(NULL, delim);
    }

    if (argc > 0) {
        const char *exe = argv[0];
        exec(exe, argv);
    }

cleanup:
    free(argv);
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
