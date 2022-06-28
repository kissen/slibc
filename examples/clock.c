#include <stdint.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char **argv)
{
	clock_t exec_time;
	(void)argc;

	printf("%s: please be patient, shaving jaks...\n", *argv);
	for (volatile uint64_t iter = 0; iter < 1000000000ULL; ++iter)
		;

	if ((exec_time = clock()) == -1)
	{
		perror("clock");
		return 1;
	}

	printf("clock(ticks)=%d clock(sec)=%d clocks_per_tick=%d\n", (int)exec_time,
		   (int)(exec_time / CLOCKS_PER_SEC), (int)CLOCKS_PER_SEC);
	return 0;
}
