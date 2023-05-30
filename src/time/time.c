#include "time.h"
#include "slibc.h"
#include "sys/syscall.h"

time_t time(time_t *tptr)
{
	return slibc_syscall_and_set1(SYS_time, (uint64_t)tptr);
}
