#include "errno.h"
#include "slibc.h"
#include "stdlib.h"
#include "unistd.h"

ssize_t write(int fd, const void *buf, size_t count)
{
    const ssize_t result = slibc_syscall3(1, fd, (slibc_u64) buf, count);

    if (result < 0) {
        errno = labs(result);
        return -1;
    }

    return result;
}
