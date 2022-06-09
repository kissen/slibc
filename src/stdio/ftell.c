#include "errno.h"
#include "stdio.h"

#include "file.h"

long ftell(FILE *stream)
{
	return stream->position;
}
