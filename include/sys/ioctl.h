#pragma once

#define TIOCGWINSZ 0x5413

struct winsize
{
	unsigned short ws_row;
	unsigned short ws_col;
	unsigned short ws_xpixel;
	unsigned short ws_ypixel;
};

/**
 * The ioctl system call. Ugh.
 */
int ioctl(int fd, unsigned long req, ...);
