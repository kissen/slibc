#pragma once

/**
 * Wall time in seconds.
 */
typedef long long time_t;

/**
 * Execution time in microseconds (µs).
 */
typedef long long clock_t;

/**
 * Given some clock_t value t, divide t by CLOCKS_PER_SEC to get time t in
 * seconds.
 */
#define CLOCKS_PER_SEC ((clock_t) 1000000)

/**
 * On success, return current unix time stamp. If tptr is non-NULL, the result
 * is then also written to *tptr. Returns (time_t) -1 on error.
 */
time_t time(time_t *tptr);

/**
 * Return execution time.
 */
clock_t clock(void);
