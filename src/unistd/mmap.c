#include "errno.h"
#include "slibc.h"
#include "unistd.h"

#include "unistd/linux.h"

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
    void *const result = (void *) slibc_syscall6(9, (slibc_u64) addr, length, prot, flags, fd, offset);

    if (linux_is_error(result)) {
        errno = linux_get_error_from(result);
        return MAP_FAILED;
    }

    return (void *) result;
}
