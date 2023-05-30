#include "getopt.h"
#include "assert.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//
// Our implementation of getopt.  Bugs ahead! This implementaiton is quite bad
// and did not see the attention it deserves.
//

static int current_argc;
static char **current_argv;
static bool current_done;

struct parsed_flag
{
	char flag;
	bool has_value;
	bool registered;
};

static const struct parsed_flag *get_flag(const char *arg, const char *options)
{
	// First check for the leading '-' character.

	if (!arg)
	{
		return NULL;
	}

	if (strlen(arg) < 2)
	{
		return NULL;
	}

	if (*arg != '-')
	{
		return NULL;
	}

	// We have something looks like a flag. Parse it; in particular check
	// whether it was registered (i.e. it is part of options).

	static struct parsed_flag return_value;

	const char flag_char = arg[1];
	const char *const needle = strchr(options, flag_char);

	if (!needle)
	{
		return_value.flag = flag_char;
		return_value.has_value = false;
		return_value.registered = false;
		return &return_value;
	}

	// We have a winner here. Fill in the remainig fields and return.

	return_value.flag = flag_char;
	return_value.has_value = *(needle + 1) == ':';
	return_value.registered = true;

	return &return_value;
}

static void fail_with(const char *cmd, const char *reason, const char flag)
{
	fprintf(stderr, "%s: option -%c: %s\n", cmd, (int)flag, reason);
	exit(EXIT_FAILURE);
}

int getopt(int argc, char *const argv[], const char *options)
{
	// At the very least we need a program name.

	if (argc < 1 || *argv == NULL)
	{
		return -1;
	}

	// Initalize if necessary.

	if (current_argc != argc || current_argv != argv)
	{
		current_argc = argc;
		current_argv = (char **)argv;
		optind = 1;
		current_done = false;
	}

	// Check if we ran out of arguments.

	if (current_done || optind >= argc)
	{
		current_done = true;
		return -1;
	}

	// Parse the next element.

	const char *arg = argv[optind];
	const struct parsed_flag *parsed = get_flag(arg, options);

	// If we have reached the first non-flag arg, we are done. Typical
	// implementations of getopt also support trailing arguments and many other
	// fancy features; we do not at this point.

	if (!parsed)
	{
		current_done = true;
		return -1;
	}

	// Handle special case where an illegal flag was passed.

	if (!parsed->registered)
	{
		if (opterr)
		{
			fail_with(*argv, "unknown flag", parsed->flag);
		}
	}

	if (parsed->registered && parsed->has_value)
	{
		// If we have an option (i.e. something like -n 1992) we have to update
		// optarg as well. Here we also check whether the flag is registered. If
		// it is not, it is better not to print error message that might make
		// the user suspect that the flag is actually valid. After all, why would
		// we request an argument for a flag that never was valid in the first place?
		if (optind + 2 >= argc)
		{
			fail_with(*argv, "missing value", parsed->flag);
		}

		optarg = argv[optind + 1];
		optind += 2;
	}
	else
	{
		// If we only have a flag, well we don't have to do as much checking.
		// Note that we also run this code in case we have an illegal flag
		// (return '?'). We have to run this because the application handles
		// the error and might still call getopt again.
		optind += 1;
		optarg = NULL;
	}

	if (!parsed->registered)
	{
		return '?';
	}

	return parsed->flag;
}
