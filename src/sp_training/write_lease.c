#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

void sigHandler(int sig) {
	printf("Caught signal - %d\n", sig);
	exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
	const char *pathname;
	int fd, ret;

	if (argc != 2) {
		printf("Usage: %s /path/to/filename \n", program_invocation_short_name);
		exit(EXIT_FAILURE);
	}

	pathname = argv[1];

	fd = open(pathname, O_RDWR);
	if (fd == -1) {
		printf("Error: open() failed - %m\n");
		exit(EXIT_FAILURE);
	}

	signal(SIGIO, sigHandler);
	ret =  fcntl(fd, F_SETLEASE, F_WRLCK);
	if (ret == -1) {
		printf("Error\n");
		exit(EXIT_FAILURE);
	}

	getchar();
	return 0;
}
