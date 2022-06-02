#include "errno.h"
#include "stdint.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"

#include "file.h"

static char get_random_ascii_char(void)
{
	static const char choices[] = "abcdefghijklmnopqrstuvwxzyABCDEFGHIJKLMNOPQRSTUVWXZY0123456789";
	const size_t number_of_choices = sizeof(choices) - 1; // do not include terminating zero

	static struct random_data rng;
	int32_t random_number;

	if (random_r(&rng, &random_number))
	{
		return 'x';
	}

	const size_t idx = ((size_t)random_number) % number_of_choices;
	return choices[idx];
}

static const char *get_random_filename(void)
{
	static const size_t random_count = 16;

	static char random_letters[32];
	static char filename[64];

	for (size_t i = 0; i < random_count; ++i)
	{
		random_letters[i] = get_random_ascii_char();
	}

	snprintf(filename, sizeof(filename), "/tmp/%s", random_letters);
	return filename;
}

static void tmpfile_on_close_func(FILE *fp)
{
	if (!fp || !fp->parg)
	{
		return;
	}

	const char *const path = fp->parg;
	unlink(path);

	free(fp->parg);
}

FILE *tmpfile(void)
{
	FILE *fp = NULL;
	char *random_file_name_malloced = NULL;

	// Create random file.

	const char *const random_file_name_static = get_random_filename();

	if (!(fp = fopen(random_file_name_static, "w+")))
	{
		goto error;
	}

	// Set up destructor.

	if (!(random_file_name_malloced = strdup(random_file_name_static)))
	{
		goto error;
	}

	fp->on_close_func = tmpfile_on_close_func;
	fp->parg = random_file_name_malloced;

	// Success!

	return fp;

error:;
	const int error = errno;

	free(random_file_name_malloced);
	fclose(fp);

	errno = error;
	return NULL;
}
