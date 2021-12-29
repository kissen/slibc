#include "slibc.h"
#include "stdlib.h"

#include "unistd/linux.h"

slibc_i64 linux_get_error_from(void *ptr)
{
    return labs((slibc_i64) ptr);
}
