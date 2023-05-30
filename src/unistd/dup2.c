#include "slibc.h"
#include "sys/syscall.h"
#include "unistd.h"

int dup2(int old, int new)
{
	return slibc_syscall_and_set2(SYS_dup2, (uint64_t)old, (uint64_t) new);
}
