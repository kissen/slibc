#include <stdio.h>
#include <string.h>

static char *without_newline(char *s)
{
    char *pos = strchr(s, '\n');
    if (pos) {
        *pos = 0;
    }
    return s;
}

int main(void)
{
    static char buf[16];

    while (fgets(buf, sizeof(buf), stdin)) {
        const size_t len = strlen(buf);
        printf("%d: %s\n", (int) len, without_newline(buf));
    }

    return 0;
}
