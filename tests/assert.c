#include <assert.h>
#include <stdio.h>

int main(void)
{
	assert(1 == 2);
	puts("this line should not print!");
	return 1;
}
