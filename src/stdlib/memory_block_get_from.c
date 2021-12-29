#include "stddef.h"

#include "stdlib/memory_block.h"

struct memory_block *memory_block_get_from(void *mallocptr)
{
	if (!mallocptr)
	{
		return NULL;
	}

	return ((struct memory_block *)mallocptr) - 1;
}
