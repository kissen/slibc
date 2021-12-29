#include "errno.h"
#include "slibc.h"
#include "stddef.h"

slibc_u64 *slibc_safe_multiply_u64(slibc_u64 lhs, slibc_u64 rhs, slibc_u64 *product)
{
	const slibc_u64 result = lhs * rhs;

	if (result / rhs != lhs)
	{
		errno = ERANGE;
		return NULL;
	}

	*product = result;
	return product;
}
