#include "slibc.h"
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

#include "stdio/file.h"

extern int main(int, char **, char **);

static void set_up_std_files(void)
{
	static FILE in = {
		.fd = STDIN_FILENO,
	};

	static FILE out = {
		.fd = STDOUT_FILENO,
	};

	static FILE err = {
		.fd = STDERR_FILENO,
	};

	stdin = &in;
	stdout = &out;
	stderr = &err;
}

void slibc_start(int argc, char **argv)
{
	set_up_std_files();

	environ = argv + argc + 1;
	const int return_value = main(argc, argv, environ);
	exit(return_value);
}
