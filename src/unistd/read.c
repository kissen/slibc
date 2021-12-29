#include "errno.h"
#include "slibc.h"
#include "stdlib.h"
#include "unistd.h"

ssize_t read(int fd, void *buf, size_t count)
{
    const slibc_i64 result = slibc_syscall3(2, fd, (slibc_u64) buf, count);

    if (result < 0) {
        errno = labs(result);
        return -1;
    }

    return result;
}
