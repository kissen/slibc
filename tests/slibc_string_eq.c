#include <munit.h>
#include <slibc.h>

int main(void)
{
	munit_assert(slibc_string_eq("hello", "hello"));
	munit_assert_false(slibc_string_eq("hello", "world"));
	munit_assert_false(slibc_string_eq("hello", NULL));
	munit_assert_false(slibc_string_eq(NULL, "world"));
	munit_assert(slibc_string_eq(NULL, NULL));

	return 0;
}
