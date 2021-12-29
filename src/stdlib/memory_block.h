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
