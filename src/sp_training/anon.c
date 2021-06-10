#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
//#include <sys/memfd.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>

int main (int argc, char *argv[]) {
	int 			md;
	unsigned int 	flags;
	const char 		*fd_str;
	ssize_t			rec;
	
	printf("PID = %u\n", getpid());

	if (argc != 2) {
		printf("Invalid number of args\n");
		exit(EXIT_FAILURE);
	}

	//int memfd_create(const char *name, unsigned int flags);
	flags = (MFD_ALLOW_SEALING);	
	
	if ((md = memfd_create(argv[1], flags)) == -1) {
		int err = errno;
		printf("memfd_create() failed - %m\n");
		exit(EXIT_FAILURE);
	}

	fd_str = "Hey India";

	if ((rec = write(md, fd_str, strlen(fd_str))) == (ssize_t) -1) {
		printf("write() failed - %m\n");
		exit(EXIT_FAILURE);
	}

	pause();
	
	return 0;
	
}
