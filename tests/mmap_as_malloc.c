#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define PROT_READ 0x01
#define PROT_WRITE 0x02

#define MAP_PRIVATE 0x02
#define MAP_ANONYMOUS 0x20

int main(void)
{
    // https://stackoverflow.com/a/4779245

    void *const addr = NULL;
    const size_t len = 1024 * 1024;
    const int prot = PROT_READ | PROT_WRITE;
    const int flag = MAP_PRIVATE | MAP_ANONYMOUS;
    const int fd = -1;
    const off_t off = 0;

    char *const my_memory = mmap(addr, len, prot, flag, fd, off);
    if (!my_memory) {
        return errno;
    }

    for (size_t i = 0; i < len; ++i) {
        const char c = ((i % 26) + 'a');
        my_memory[i] = c;
    }

    for (size_t i = 0; i < len; ++i) {
        const char c = my_memory[i];
        fputc(c, stdout);
    }

    return 0;
}
