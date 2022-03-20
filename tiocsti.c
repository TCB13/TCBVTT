#include <unistd.h>
#include <err.h>
#include <stdio.h>
#include "sys/ioctl.h"

char *progname;

static int usage() {
	printf("Usage: echo \"text\" | %s > /dev/ttyXY\n", progname);
	return 2;
}

int main(int argc, char **argv) {

	progname = argv[0];

	if (isatty(STDIN_FILENO)) {
		return usage();
    }

	char c;
	ssize_t r;
	while ((r = read(0, & c, 1)) > 0) {
		if (ioctl(1, TIOCSTI, & c)) {
			err(1, "ioctl(TIOCSTI)");
		}
	}
	if (r < 0) {
		err(1, "read");
	}
	return 0;
}
