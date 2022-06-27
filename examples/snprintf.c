#include <stdio.h>

int main(void)
{
	static char buf[8];
	snprintf(buf, 4, "%d%d%d%d%d%d%d%d", 1, 2, 3, 4, 5, 6, 7, 8);
	puts(buf);

	return 0;
}
