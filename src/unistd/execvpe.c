#include "errno.h"
#include "slibc.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"

int execvpe(const char *file, char *const argv[], char *const envp[])
{
	// If file is weird, don't even bother.

	const size_t file_len = slibc_string_len(file);

	if (!file_len)
	{
		errno = ENOENT;
		return -1;
	}

	// If file is an absolute path, then we can just exec as-is.

	if (file[0] == '/')
	{
		return execve(file, argv, envp);
	}

	// File is a relative path. Time to try out all entries in PATH.

	const char *const path = getenv("PATH");
	if (!path)
	{
		errno = ENOENT;
		return -1;
	}

	// We make a copy of the PATH variable. That makes the following code easier
	// as we can mutate pathcpy as we wish.

	char *pathcpy = NULL;
	char *abspath = NULL;

	pathcpy = strdup(path);
	if (!pathcpy)
	{
		goto fail;
	}

	char *pathptr = pathcpy;

	while (*pathptr)
	{
		// Remove terminating ':' if there are any. The last entry does not
		// necessarly have ':'.

		char *const end = strchr(pathptr, ':');
		if (end)
		{
			*end = 0;
		}

		// Construct the absolute path.

		const size_t abspath_len = strlen(pathptr) + 1 + file_len + 1;
		if (!(abspath = malloc(abspath_len)))
		{
			goto fail;
		}

		sprintf(abspath, "%s/%s", pathptr, file);

		// With the absolut path in hand, we can try executing that abs path.
		// If execve succeeds, it does not return.

		execve(abspath, argv, envp);

		if (errno != ENOENT)
		{
			goto fail;
		}

		// Well this loop iterations did not lead us to success. But we can
		// always try again with the next element in PATH.

		free(abspath);
		abspath = NULL;

		if (!end)
		{
			errno = ENOENT;
			goto fail;
		}

		pathptr = end + 1;
	}

fail:;
	const int error = errno;

	free(abspath);
	free(pathcpy);

	errno = error;
	return -1;
}
