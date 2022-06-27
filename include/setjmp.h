#pragma once

typedef struct
{
    unsigned long long ip;
    unsigned long long sp;
} jmp_buf;

/**
 * Write jump information to env.
 *
 * @return 0 on inital store and some non-zero value if being jumped to.
 */
int setjmp(jmp_buf env);

/**
 * Jump to env previously set up with a call to setjmp(3).
 */
void longjmp(jmp_buf env, int val);
