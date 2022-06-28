#include "sys/times.h"
#include "slibc.h"
#include "sys/syscall.h"

clock_t times(struct tms *buf)
{
	return slibc_syscall_and_set1(SYS_times, (slibc_u64)buf);
}
