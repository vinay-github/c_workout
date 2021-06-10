#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
	int 	fd, len, tbuf;
	long int 	size;
	int		buffersize = 10;
	char	buf[buffersize];
	char	*buf2;
	struct 	stat	sb;
	
	if ( argc != 2 ) {
		printf("Usage: %s file_name\n", argv[0]);
		exit(EXIT_FAILURE);
	}

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
	printf("The size of file is %ld\n", size);

/* This prints the whole file char by char backwards */
	while ( size > 0 ) {
		memset(buf, 0, buffersize);
	
		if (size > buffersize) 
			tbuf = buffersize - 1;
		else
			tbuf = size;

		lseek(fd, (off_t) size - tbuf, SEEK_SET);

		if ( read(fd, &buf, tbuf ) == -1) {
			printf("Error - %m\n");
			exit(EXIT_FAILURE);
		}
		printf("%s", buf);
		size-=tbuf;
	}
	
	return 0;
}
	
