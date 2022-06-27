#include <slibc.h>

int main(void)
{
	const int exit_syscall_id = 60;
	const int exit_code = 92;

	slibc_syscall1(exit_syscall_id, exit_code);
	return 0;
}
