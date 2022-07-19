#pragma once

typedef struct
{
	unsigned long long rbx;
	unsigned long long rbp;
	unsigned long long r12;
	unsigned long long r13;
	unsigned long long r14;
	unsigned long long r15;
	unsigned long long rsp;
} jmp_buf;

/**
 * Write jump information to env.
 *
 * @return 0 on inital store and some non-zero value if being jumped to.
 */
int setjmp(jmp_buf *env);
#define setjmp(ENV) setjmp(&ENV)

/**
 * Jump to env previously set up with a call to setjmp(3).
 */
void longjmp(const jmp_buf *env, int val);
#define longjmp(ENV, VAL) longjmp(&ENV, VAL)
