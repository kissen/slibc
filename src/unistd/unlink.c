#include "slibc.h"
#include "sys/syscall.h"
#include "unistd.h"

int unlink(const char *dir)
{
	return slibc_syscall_and_set1(SYS_unlink, (slibc_u64)dir);
}
