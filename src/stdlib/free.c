#include "stdlib.h"
#include "unistd.h"

#include "stdlib/memory_block.h"

void free(void *ptr)
{
    // We do nothing on NULL.

    if (!ptr) {
        return;
    }

    // Check whether the magic is set. This is to get some
    // sanity checking whether ptr was actually allocated.

    struct memory_block *block = memory_block_get_from(ptr);

    if (block->magic != MEMORY_BLOCK_MAGIC) {
        abort();
    }

    block->magic = 0;

    // Now we can unmap that memory.

    const size_t original_mmap_size = block->len + sizeof(*block);

    if (munmap(block, original_mmap_size) == -1) {
        abort();
    }
}
