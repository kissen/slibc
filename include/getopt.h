#pragma once

extern char *optarg;
extern int optind, opterr, optopt;

/**
 * Parse command line arguments. We only support basic getopt features,
 * certainly we do not support any of the GNU extensions.
 */
int getopt(int argc, char *const argv[], const char *options);
