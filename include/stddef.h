#pragma once

#include "slibc.h"

// (7.19) Common Definitions

typedef slibc_imax ptrdiff_t;
typedef slibc_umax size_t;
typedef slibc_imax max_align_t;

#define NULL ((void*) 0)
