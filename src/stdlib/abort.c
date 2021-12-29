#include "signal.h"
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

void abort(void)
{
	// TODO: unblock signal first

	const pid_t self = getpid();
	const int sigabrt = 6;

	if (kill(self, sigabrt) == -1)
	{
		perror("abort: kill");
	}

	exit(99);
}
