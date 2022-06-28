#include "sys/times.h"
#include "time.h"

clock_t clock(void)
{
	struct tms ts;

	if (times(&ts) == -1)
	{
		return -1;
	}

	const clock_t total_exec_time = ts.tms_utime + ts.tms_stime + ts.tms_cutime + ts.tms_cstime;
	return total_exec_time * 10 * 1000;
}
