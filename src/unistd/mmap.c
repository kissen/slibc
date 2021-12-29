#include "errno.h"
#include "stdlib.h"
#include "unistd.h"

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
    const slibc_u64 result = slibc_syscall6(9, (slibc_u64) addr, length, prot, flags, fd, offset);

    if (result < 0) {
        errno = labs(result);
        return MAP_FAILED;
    }

    return (void *) result;
}
