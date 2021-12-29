#include "errno.h"
#include "stdlib.h"
#include "unistd.h"

#include "stdlib/memory_block.h"

#define PROT_READ 0x01
#define PROT_WRITE 0x02

#define MAP_PRIVATE 0x02
#define MAP_ANONYMOUS 0x20

static size_t match_to_page_size(size_t n)
{
    const size_t page_size = 4096;
    const size_t required = n + sizeof(struct memory_block);
    return (required / page_size + 1) * page_size;
}

void *malloc(size_t requested_size)
{
    // Run a matching mmap call.

    void *const addr = NULL;
    const size_t mmap_len = match_to_page_size(requested_size);
    const int prot = PROT_READ | PROT_WRITE;
    const int flag = MAP_PRIVATE | MAP_ANONYMOUS;
    const int fd = -1;
    const off_t off = 0;

    void *const allocated = mmap(addr, mmap_len, prot, flag, fd, off);

    // On error, there is little we can do.

    if (allocated == MAP_FAILED) {
        errno = ENOMEM;
        return NULL;
    }

    // On success initalize the memory_block and return the matching memory.

    struct memory_block *const block = allocated;
    block->magic = MEMORY_BLOCK_MAGIC;
    block->len = mmap_len - sizeof(struct memory_block);

    return block->bytes;
}
