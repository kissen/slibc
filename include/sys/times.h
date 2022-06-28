#pragma once

#include <time.h>

struct tms
{
	clock_t tms_utime;
	clock_t tms_stime;
	clock_t tms_cutime;
	clock_t tms_cstime;
};

/**
 * Request execution time from kernel.
 */
clock_t times(struct tms *buf);
