#include "string.h"

int strncmp(const char *s, const char *t, size_t n)
{
    for (size_t i = 0; i < n; ++i) {
        const char schar = s[i];
        const char tchar = t[i];

        if (schar == 0 && tchar == 0) {
            return 0;
        }

        if (schar == 0 && tchar != 0) {
            return 1;
        }

        if (schar != 0 && tchar == 0) {
            return -1;
        }

        if (schar < tchar) {
            return -1;
        }

        if (schar > tchar) {
            return 1;
        }
    }

    return 0;
}
