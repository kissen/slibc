#pragma once

#include "slibc.h"
#include "stddef.h"

#define MEMORY_BLOCK_MAGIC 0x19920501

struct memory_block
{
	slibc_u32 magic;
	size_t len;
	char bytes[];
};

/**
 * Given mallocptr as returned from a function like malloc, calloc and so on,
 * return a pointer to the underlying memory_block. If mallocptr is NULL,
 * this function also returns NULL.
 */
struct memory_block *memory_block_get_from(void *mallocptr);
