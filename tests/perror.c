#include <errno.h>
#include <stdio.h>

int main(void)
{
    errno = ENOMEM;
    perror("ENOMEM");

    errno = EDOM;
    perror("EDOM");

    return 0;
}
