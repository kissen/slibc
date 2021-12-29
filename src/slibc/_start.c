#include "slibc.h"
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

#include "stdio/file.h"

extern int main(void);

static void set_up_std_files(void)
{
    static FILE in = {
        .fd = STDIN_FILENO
    };

    static FILE out = {
        .fd = STDOUT_FILENO
    };

    static FILE err = {
        .fd = STDERR_FILENO
    };

    stdin = &in;
    stdout = &out;
    stderr = &err;
}

void _start(void)
{
    set_up_std_files();

    const int return_value = main();
    exit(return_value);
}
