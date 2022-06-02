#pragma once

#include "stdint.h"
#include "stdio.h"

#define FILE_FLAGS_ERROR 1
#define FILE_FLAGS_EOF 2

/**
 * FILE structure as used in slibc.
 */
struct FILE
{
	/** The underlying Unix file descriptor. */
	int fd;

	/** Flags that store various information. */
	uint32_t flags;

	/** Number of elements currently pushed back by calls to ungetc. */
	int nunget;

	/** The cache for ungetc. We currently only support one byte. */
	unsigned char unget;

	/** Function to be called just after close(). */
	void (*on_close_func)(FILE *);

	/** Additional member that may be used internally by slibc. */
	void *parg;
};
