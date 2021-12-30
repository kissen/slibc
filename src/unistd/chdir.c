#include "slibc.h"
#include "sys/syscall.h"
#include "unistd.h"

int chdir(const char *dir)
{
	return slibc_syscall_and_set1(SYS_chdir, (slibc_u64)dir);
}
