#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    const pid_t pid = fork();
    const pid_t mypid = getpid();
    printf("fork() = %d, getpid() = %d\n", pid, mypid);
    return 0;
}
