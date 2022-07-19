#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	jmp_buf buf;
	int retval;

	printf("%s:%d: about to call setjmp...\n", __FILE__, __LINE__);

	if ((retval = setjmp(buf)) == 0)
	{
		printf("%s:%d: setjmp returned %d, now calling longjmp...\n", __FILE__, __LINE__, retval);
		longjmp(buf, 69);
	}
	else
	{
		printf("%s:%d: setjmp returned %d, quitting...\n", __FILE__, __LINE__, retval);
		exit(0);
	}

	printf("%s:%d: reached end, this should not happen...\n", __FILE__, __LINE__);
	return 1;
}
