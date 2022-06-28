#pragma once

typedef unsigned long long time_t;

/**
 * On success, return current unix time stamp. If tptr is non-NULL, the result
 * is then also written to *tptr. Returns (time_t) -1 on error.
 */
time_t time(time_t *tptr);
