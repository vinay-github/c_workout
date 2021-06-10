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
	char		*buf, *result_buf;
	struct 		stat	sb_st;
	
	if ( argc != 2 ) {
		printf("Usage: %s file_name\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((fd = open(argv[1], O_RDONLY)) == -1) {
		printf("Failed to open the file %s - Error %s\n",argv[1], strerror(errno));
		exit(EXIT_FAILURE);
	}
	
	if ((stat(argv[1], &sb_st)) == -1 ) {
		printf("Failed to get file status %s\n", strerror(errno));
		goto error_exit;
	}

	size = sb_st.st_size;
	buf = (char*)malloc(size+1);
	memset(buf, 0, size+1);

	if ((lseek (fd,  (off_t) 0, SEEK_SET)) == (off_t) -1) {
		printf("File repositioning error %m\n");
		goto error_exit;
	}

	if ((read (fd, buf, size)) == -1) {
		printf("read() error - %m\n");
		goto error_exit;
	}

	for (i = size-2; i >= 0; i--) {
		len++;

		if (buf[i] == '\n') {									// When iteration reached the new line character
			result_buf = (char *)malloc(len * sizeof(char));
			memset(result_buf, 0, len * sizeof(char));

			if ((lseek(fd, (off_t) i+1, SEEK_SET)) == (off_t) -1) {
				printf("File repositioning error %m\n");
				goto error_exit;
			}

			read (fd, result_buf, len);
			printf("%.*s",len, result_buf);
			
			len = 0;
			free(result_buf);	
		}
		else if ((i-1) == 0) {									// reached the first character
			result_buf = (char *)malloc(sizeof(char)*len);
			memset(result_buf, 0, sizeof(char)*len);
			
			if ((lseek(fd, (off_t) i-1, SEEK_SET)) == (off_t) -1) {
				printf("File repositioning error %m\n");
				goto error_exit;
			}

			read(fd, result_buf, len+1);
			result_buf[len+1] = buf[size-1];
			
			printf("%.*s", len+2, result_buf);
			free(result_buf);
		}
	}
	
	free(buf);
	return 0;

error_exit:
	close(fd);
	exit(EXIT_FAILURE);
}
	
