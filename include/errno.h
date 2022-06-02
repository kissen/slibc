#pragma once

// (7.5) Errors

#define EPERM 1
#define ENOENT 2
#define ENOMEM 12
#define EACCES 13
#define EINVAL 22
#define EDOM 33
#define ERANGE 34
#define EILSEQ 84

extern int errno;
