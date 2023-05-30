#include "sys/times.h"
#include "slibc.h"
#include "sys/syscall.h"

clock_t times(struct tms *buf)
{
	return slibc_syscall_and_set1(SYS_times, (uint64_t)buf);
}
