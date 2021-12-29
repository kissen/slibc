#include <stdio.h>

int main()
{
    const char *message = "Brief aus dem Gefängnis";
    return fputs(message, stderr);
}
