#include "errno.h"
#include "slibc.h"
#include "stdlib.h"
#include "string.h"

#include "stdlib/memory_block.h"

void *realloc(void *ptr, size_t size)
{
    // If ptr is NULL, realloc acts like malloc.

    if (!ptr) {
        return malloc(size);
    }

    // If size is 0, realloc acts like free.

    if (ptr && size == 0) {
        free(ptr);
        return NULL;
    }

    // Check out the block. We do a sanity check to catch user errors and the
    // size to see whether we even need to do anything.

    const struct memory_block *const block = memory_block_get_from(ptr);

    if (block->magic != MEMORY_BLOCK_MAGIC) {
        abort();
    }

    if (block->len >= size) {
        return ptr;
    }

    // We do need to increase the size. Simply allocate a new block and then
    // copy everything.

    void *const new_memory = malloc(size);
    if (!new_memory) {
        return NULL;
    }

    const size_t bytes_to_copy = SLIBC_MIN(block->len, size);
    memcpy(new_memory, ptr, bytes_to_copy);
    free(ptr);

    return new_memory;
}
