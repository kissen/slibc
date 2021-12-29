#include "stdio.h"

#include "stdio/file.h"

void clearerr(FILE *stream)
{
    if (stream) {
        stream->flags &= ~FILE_FLAGS_ERROR;
    }
}
