#include "slibc.h"
#include "unistd.h"

ssize_t write(int fd, const void *buf, size_t count)
{
    return slibc_syscall3(1, fd, (slibc_u64) buf, count);
}
