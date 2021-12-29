#include "stddef.h"
#include "stdio.h"

#include "stdio/file.h"

int ferror(FILE *stream)
{
    return (stream != NULL) && (stream->flags & FILE_FLAGS_ERROR);
}
