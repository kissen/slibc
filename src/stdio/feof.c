#include "stddef.h"
#include "stdio.h"

#include "stdio/file.h"

int feof(FILE *stream)
{
    return (stream != NULL) && (stream->flags & FILE_FLAGS_EOF);
}
