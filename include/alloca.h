#pragma once

#include <stddef.h>

/**
 * Allocate nbytes on the stack.
 */
#define alloca __builtin_alloca
