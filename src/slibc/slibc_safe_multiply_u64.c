#include "errno.h"
#include "slibc.h"
#include "stddef.h"

uint64_t *slibc_safe_multiply_u64(uint64_t lhs, uint64_t rhs, uint64_t *product)
{
	const uint64_t result = lhs * rhs;

	if (result / rhs != lhs)
	{
		errno = ERANGE;
		return NULL;
	}

	*product = result;
	return product;
}
