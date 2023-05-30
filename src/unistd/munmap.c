#include "slibc.h"
#include "sys/syscall.h"
#include "unistd.h"

int munmap(void *addr, size_t length)
{
	return slibc_syscall_and_set2(SYS_munmap, (uint64_t)addr, (uint64_t)length);
}
