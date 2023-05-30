#include "assert.h"
#include "slibc.h"
#include "sys/syscall.h"
#include "unistd.h"

pid_t getpid(void)
{
	const int64_t result = slibc_syscall0(SYS_getpid);
	assert(result >= 0);
	return result;
}
