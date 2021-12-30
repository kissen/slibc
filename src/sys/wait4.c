#include "errno.h"
#include "slibc.h"
#include "sys/syscall.h"
#include "sys/wait.h"

pid_t wait4(pid_t pid, int *wstatus, int options, struct rusage *ru)
{
	const slibc_u64 wstatus64 = (slibc_u64)wstatus;
	const slibc_u64 ru64 = (slibc_u64)ru;

	return slibc_syscall_and_set4(SYS_wait4, pid, wstatus64, options, ru64);
}
