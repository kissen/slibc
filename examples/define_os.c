#include <stdio.h>
#include <unistd.h>

int main(void)
{
#ifdef unix
	puts("unix!");
#endif

#ifdef linux
	puts("linux!");
#endif

#ifdef __unix__
	puts("__unix__!");
#endif

#ifdef __linux__
	puts("__linux__!");
#endif

	return 0;
}
