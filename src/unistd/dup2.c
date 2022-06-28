#include "slibc.h"
#include "sys/syscall.h"
#include "unistd.h"

int dup2(int old, int new)
{
	return slibc_syscall_and_set2(SYS_dup2, (slibc_u64)old, (slibc_u64) new);
}
