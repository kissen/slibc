#include <munit.h>
#include <stdio.h>

int main(void)
{
	int a, b, c;
	const int n = sscanf("1 2 3", "%d %d %d", &a, &b, &c);

	munit_assert_int(n, ==, 3);
	munit_assert_int(a, ==, 1);
	munit_assert_int(b, ==, 2);
	munit_assert_int(c, ==, 3);

	return 0;
}
