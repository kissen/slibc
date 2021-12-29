#include "slibc.h"
#include "stdlib.h"

extern int main(void);

void _start(void)
{
    const int return_value = main();
    exit(return_value);
}
