#include "errno.h"
#include "string.h"

const char *error_to_string(int errnum)
{
    switch (errnum) {
        case ENOMEM:
            return "out of memory";
        case EINVAL:
            return "invalid argument";
        case EDOM:
            return "domain eror";
        case ERANGE:
            return "range error";
        case EILSEQ:
            return "EILSEQ";
        case 0:
            return "success (no error)";
        default:
            return "unknown error";
    }
}

char *strerror(int errnum)
{
    return (char *) error_to_string(errnum);
}
