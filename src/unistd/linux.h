#pragma once

#include "slibc.h"
#include "stdbool.h"

/**
 * Return whether ptr contains an error code.
 */
bool linux_is_error(void *ptr);

/**
 * Return the error code from ptr. You should check with
 * linux_is_error first though.
 */
slibc_i64 linux_get_error_from(void *ptr);
