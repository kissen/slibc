#include "sys/syscall.h"
#include "assert.h"
#include "errno.h"
#include "slibc.h"
#include "stdarg.h"
#include "stdbool.h"
#include "stdlib.h"
#include "unistd.h"

#include "unistd/linux.h"

#define UNKNOWN_SYSCALL_NUMBER -1
#define MAX_NUMBER_OF_ARGUMENTS 6

static int pointer_returned_from(long syscall_number)
{
	switch (syscall_number)
	{
	case SYS_getpid:
	case SYS_fork:
	case SYS_chdir:
	case SYS_stat:
	case SYS_munmap:
	case SYS_read:
	case SYS_write:
	case SYS_execve:
	case SYS_wait4:
	case SYS_open:
	case SYS_close:
		return 0;

	case SYS_getcwd:
	case SYS_mmap:
		return 1;

	default:
		return UNKNOWN_SYSCALL_NUMBER;
	}
}

static int number_of_arguments_for(long syscall_number)
{
	switch (syscall_number)
	{
	case SYS_getpid:
	case SYS_fork:
		return 0;

	case SYS_chdir:
	case SYS_close:
		return 1;

	case SYS_stat:
	case SYS_munmap:
	case SYS_getcwd:
		return 2;

	case SYS_read:
	case SYS_write:
	case SYS_execve:
	case SYS_open:
		return 3;

	case SYS_wait4:
		return 4;

	case SYS_mmap:
		return 6;

	default:
		return UNKNOWN_SYSCALL_NUMBER;
	}
}

long syscall(long syscall_number, ...)
{
	// First parse arguments.

	const int narguments = number_of_arguments_for(syscall_number);
	if (narguments == UNKNOWN_SYSCALL_NUMBER)
	{
		errno = EINVAL;
		return -1;
	}

	const bool returns_pointer = pointer_returned_from(syscall_number);
	if (returns_pointer == UNKNOWN_SYSCALL_NUMBER)
	{
		errno = EINVAL;
		return -1;
	}

	// Extract the actual arguments from the vararg hell.

	long args[MAX_NUMBER_OF_ARGUMENTS] = {0};

	va_list vargs;
	va_start(vargs, syscall_number);

	for (int i = 0; i < MAX_NUMBER_OF_ARGUMENTS; ++i)
	{
		const long argi = va_arg(vargs, long);
		args[i] = argi;
	}

	va_end(vargs);

	// Now that we have all arguments we can issue the system call.

	long return_value;

	switch (narguments)
	{
	case 0: {
		return_value = slibc_syscall0(syscall_number);
		break;
	}

	case 1: {
		return_value = slibc_syscall1(syscall_number, args[0]);
		break;
	}

	case 2: {
		return_value = slibc_syscall2(syscall_number, args[0], args[1]);
		break;
	}

	case 3: {
		return_value = slibc_syscall3(syscall_number, args[0], args[1], args[2]);
		break;
	}

	case 4: {
		return_value = slibc_syscall4(syscall_number, args[0], args[1], args[2], args[3]);
		break;
	}

	case 6: {
		return_value =
			slibc_syscall6(syscall_number, args[0], args[1], args[2], args[3], args[4], args[5]);
		break;
	}
	}

	// Depending on the kind of system call, the kernel will either return an
	// error code or a pointer. We have to differentiate between the two cases
	// and set the errno to match the kernel error.

	if (returns_pointer)
	{
		// System calls that return pointers.

		void *const return_pointer = (void *)return_value;
		if (linux_is_error(return_pointer))
		{
			errno = linux_get_error_from(return_pointer);
			return 0; // == NULL
		}

		return return_value;
	}
	else
	{
		// System calls that return some status/error code or (byte) count.

		if (return_value < 0)
		{
			errno = labs(return_value);
			return -1;
		}

		return return_value;
	}
}
