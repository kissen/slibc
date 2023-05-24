#include <stdio.h>

int main(void)
{
	int a, b, c;
	const char *const format = "%d %d %d";

	fprintf(stderr, "calling scanf(\"%s\", &a, &b, &c)...\n", format);
	const int n = scanf(format, &a, &b, &c);

	fprintf(stderr, "scanf() -> %d a=%d b=%d c=%d\n", n, a, b, c);

	return 0;
}
