#include <time.h>
#include <stdio.h>

int main(void)
{
    const time_t TIME_ERROR = (time_t) - 1;
    time_t s, t, u;

    if ((s = time(&t)) == TIME_ERROR)
    {
        perror("time(&t)");
        return 1;
    }

    if ((u = time(NULL)) == TIME_ERROR)
    {
        perror("time(NULL)");
        return 1;
    }

    // Casting u64 -> int is obviously wrong, but as of writing this our printf
    // does not support anything but standard ints.
    printf("s=%d t=%d u=%d\n", (int) s, (int) t, (int) u);

    return 0;
}
