#include "errno.h"
#include "slibc.h"
#include "sys/syscall.h"
#include "sys/wait.h"

pid_t wait4(pid_t pid, int *wstatus, int options, struct rusage *ru)
{
	const uint64_t wstatus64 = (uint64_t)wstatus;
	const uint64_t ru64 = (uint64_t)ru;

	return slibc_syscall_and_set4(SYS_wait4, pid, wstatus64, options, ru64);
}
