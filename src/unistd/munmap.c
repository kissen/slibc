#include "errno.h"
#include "slibc.h"
#include "stdlib.h"
#include "unistd.h"

int munmap(void *addr, size_t length)
{
    const slibc_i64 result = slibc_syscall2(11, (slibc_u64) addr, length);

    if (result < 0) {
        errno = labs(result);
        return -1;
    }

    return result;
}
