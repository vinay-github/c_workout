/* Program to demostrate basic functionality of cat command */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int 	fd, size;
	char	c;
	struct 	stat statbuf_st;
	
		printf("%d\n", EXIT_FAILURE);
	if (argc != 2) {
		printf("Usage: %s file_name\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((fd = open(argv[1], O_RDONLY)) == -1) {
		printf("Error %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	
	if (stat(argv[1], &statbuf_st) != 0) {
		printf("Stat failed %s\n", strerror(errno));
		close(fd);
		exit(EXIT_FAILURE);
	}
	size = statbuf_st.st_size;

/*
	if (lseek(fd, (off_t) 0, SEEK_SET) < (off_t) 0) {
		printf("Repositioning file offset failed %s\n", strerror(errno));
		close(fd);
		return -1;
	}
*/

	while (size-- > 0) {
		if (read(fd, &c, 1) == -1) {
			printf("Failed to read\n");
			close(fd);
			exit(EXIT_FAILURE);
		}
		printf("%c", c);
	}
	close(fd);
	return 0;
}
	
