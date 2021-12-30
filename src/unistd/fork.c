#include "slibc.h"
#include "sys/syscall.h"
#include "unistd.h"

pid_t fork(void)
{
	return slibc_syscall_and_set0(SYS_fork);
}
