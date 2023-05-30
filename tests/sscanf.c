#include <munit.h>
#include <stdio.h>

static void read_integers(void)
{
	int a, b, c;
	const int n = sscanf("1 2 3", "%d %d %d", &a, &b, &c);

	munit_assert_int(n, ==, 3);
	munit_assert_int(a, ==, 1);
	munit_assert_int(b, ==, 2);
	munit_assert_int(c, ==, 3);
}

static void parse_figlet_font_header(void)
{
	// Based on figlet 2.2.5, file figlet.c.

	char c;
	int l, m, n, o, p, q;

	const char *const header = "a$ 1 2 16 32 66 1 19920 501";

	const int matched = sscanf(header, "%*c%c %d %*d %d %d %d %d %d", &c, &l, &m, &n, &o, &p, &q);

	munit_assert_int(c, ==, '$');
	munit_assert_int(l, ==, 1);
	munit_assert_int(m, ==, 16);
	munit_assert_int(n, ==, 32);
	munit_assert_int(o, ==, 66);
	munit_assert_int(p, ==, 1);
	munit_assert_int(q, ==, 19920);
	munit_assert_int(matched, ==, 7);
}

int main(void)
{
	read_integers();
	parse_figlet_font_header();

	return 0;
}
