#pragma once

/**
 * Abort program execution because expression failed. Called by
 * our assert macro.
 */
void assert_failed_with(const char *filename, int lineno, const char *function,
						const char *expression);

#ifdef NDEBUG
#define assert(EXPR) /* do nothing */
#else
#define assert(EXPR)                                                                               \
	if (!(EXPR))                                                                                   \
	{                                                                                              \
		assert_failed_with(__FILE__, __LINE__, __func__, #EXPR);                                   \
	}
#endif
