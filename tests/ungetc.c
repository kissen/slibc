#include <stdio.h>

int main(void)
{
	FILE *const stream = stdin;

	ungetc('!', stream);
	printf("%c\n", fgetc(stream));
	printf("%c\n", fgetc(stream));

	return 0;
}
