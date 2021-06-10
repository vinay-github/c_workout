/* Program to demonstrate basic functionality of tac command */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
	int 		fd, len =0, i;
	long int 	size;
	char		buf[1024 * 6];
	char		buf2[1024 * 3];
	struct 		stat	sb;
	
	if ( argc != 2 ) {
		printf("Usage: %s file_name\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	memset(buf, 0, sizeof(buf));
	memset(buf2, 0, sizeof(buf2));

	if ((fd = open(argv[1], O_RDONLY)) == -1) {
		printf("Error %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	
	if ((stat(argv[1], &sb)) == -1 )
	{
		printf("Failed to file status %s\n", strerror(errno));
		close(fd);
		exit(EXIT_FAILURE);
	}

	size = sb.st_size;

	lseek (fd,  (off_t) 0, SEEK_SET);
	if (read (fd, &buf, size) == -1) {
		printf("Error - %m\n");
		exit(EXIT_FAILURE);
	}

	for (i = size-2; i >= 0; i--) {
		len++;

		if (buf[i] == '\n') {
			lseek(fd, (off_t) i+1, SEEK_SET);
			read (fd, &buf2, len);
			printf("%s", buf2);
			
			len = 0;
			memset(buf2, 0, sizeof(buf2));
		}
		else if ((i-1) == 0) {
			lseek(fd, (off_t) i-1, SEEK_SET);
			read(fd, &buf2, len+1);
			buf2[len+1] = buf[size-1];
			printf("%s", buf2);
		}
	}

	return 0;
}
	
