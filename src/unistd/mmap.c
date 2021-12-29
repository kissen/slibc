#include "errno.h"
#include "stdlib.h"
#include "unistd.h"

#include "unistd/linux.h"

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
    void *const result = (void *) slibc_syscall6(9, (slibc_u64) addr, length, prot, flags, fd, offset);

    if (linux_is_error(result)) {
        const slibc_i64 error = linux_get_error_from(result);
        errno = labs(error);
        return MAP_FAILED;
    }

    return (void *) result;
}
