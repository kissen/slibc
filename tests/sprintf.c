#include <stdio.h>

int main(void)
{
	char buf[1024];
	const int nprinted = sprintf(buf, "%d:%d:%d:%d", 15, -25, 55, -510);
	puts(buf);
	printf("nprinted=%d\n", nprinted);
	return 0;
}
