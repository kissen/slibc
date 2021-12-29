#include "errno.h"
#include "stdlib.h"
#include "unistd.h"

#include "stdlib/memory_block.h"

#define PROT_READ 0x01
#define PROT_WRITE 0x02

#define MAP_PRIVATE 0x02
#define MAP_ANONYMOUS 0x20

void *malloc(size_t requested_size)
{
    // Run a matching mmap call.

    void *const addr = NULL;
    const size_t len = requested_size + sizeof(struct memory_block);
    const int prot = PROT_READ | PROT_WRITE;
    const int flag = MAP_PRIVATE | MAP_ANONYMOUS;
    const int fd = -1;
    const off_t off = 0;

    void *const allocated = mmap(addr, len, prot, flag, fd, off);

    // On error, there is little we can do.

    if (allocated == MAP_FAILED) {
        errno = ENOMEM;
        return NULL;
    }

    // On success initalize the memory_block and return the matching memory.

    struct memory_block *const block = allocated;
    block->magic = MEMORY_BLOCK_MAGIC;
    block->len = len;

    return block->bytes;
}
