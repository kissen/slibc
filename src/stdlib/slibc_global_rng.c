#include "slibc_global_rng.h"

struct random_data slibc_global_rng = {
	.state = 0,
};
