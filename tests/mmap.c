#include "unistd.h"

int main(void)
{
    void *addr = (void *) 0xaffe;
    size_t len = 123;
    int prot = 0xabc;
    int flag = 0xdef;
    int fd = 92;
    off_t off = 0xbadf00d;

    mmap(addr, len, prot, flag, fd, off);
    return 0;
}
