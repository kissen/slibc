#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
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

    perror("fgets");
    exit(1);
}

int main(void)
{
    while (true) {
        print_promt();
        char *const line = read_line();
    }
}
