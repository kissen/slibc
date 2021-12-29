#include "errno.h"
#include "stdlib.h"
#include "unistd.h"

ssize_t read(int fd, void *buf, size_t count)
{
    const ssize_t result = slibc_syscall3(2, fd, (slibc_u64) buf, count);

    if (result < 0) {
        errno = labs(result);
        return -1;
    }

    return result;
}
