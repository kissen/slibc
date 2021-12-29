#include <stdlib.h>
#include <errno.h>

int main(void)
{
    const size_t too_much = 1024ULL * 1024ULL * 1024ULL * 1024ULL;  // 1 TiB
    void *const ptr = malloc(too_much);

    if (ptr != NULL) {
        exit(1);
    }

    if (errno != ENOMEM) {
        exit(2);
    }

    return 0;
}
