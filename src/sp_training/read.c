/* Program to demostrate basic functionality of cat command */
#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define JUMP	8192

int main(int argc, char *argv[]) {
	int 	fd, size;
	char	c;
	struct 	stat statbuf_st;
	off_t	os;
	
	if (argc != 2) {
		printf("Usage: %s file_name\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((fd = open(argv[1], O_RDONLY)) == -1) {
		printf("Error %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	printf("argc = %p, argv = %p\n", &argc, &argv); 

	getchar();
	
	if ((os = lseek(fd, (off_t) 0, SEEK_END)) < (off_t) 0) {
		printf("Repositioning file offset failed %s\n", strerror(errno));
		close(fd);
		exit(EXIT_FAILURE);
	}

	if (readahead(fd, os - JUMP, JUMP) == (ssize_t) -1) {
		printf("Readahead failed - %m");
		close(fd);
		exit(EXIT_FAILURE);
	}

	close(fd);
	return 0;
}
	
