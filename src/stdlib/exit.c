#include "slibc.h"
#include "stdlib.h"

void exit(int status)
{
    slibc_syscall1(60, status);
}
