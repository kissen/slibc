#pragma once

#include "stdint.h"
#include "stdio.h"

static const uint32_t FILE_FLAGS_ERROR = 1;
static const uint32_t FILE_FLAGS_EOF = 2;

struct FILE
{
    int fd;
    uint32_t flags;
};
