#include <stdio.h>
#include <string.h>

static void print_tokens(char *s)
{
    int i = 0;
    char *token = strtok(s, " ");

    while (token) {
        printf("[%d] %s\n", i++, token);
        token = strtok(NULL, " ");
    }
}

int main(void)
{
    char buf[4096];

    while (fgets(buf, sizeof(buf), stdin)) {
        char *const newline = strchr(buf, '\n');
        if (newline) {
            *newline = 0;
        }

        print_tokens(buf);
    }

    return 0;
}
