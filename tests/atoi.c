#include <munit.h>
#include <stdlib.h>

int main(void)
{
	munit_assert_int(atoi("0"), ==, 0);
	munit_assert_int(atoi("1"), ==, 1);
	munit_assert_int(atoi("10"), ==, 10);
	munit_assert_int(atoi("100"), ==, 100);

	return 0;
}
