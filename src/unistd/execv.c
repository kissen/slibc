#include "unistd.h"

int execv(const char *file, char *const argv[])
{
    return execve(file, argv, environ);
}
