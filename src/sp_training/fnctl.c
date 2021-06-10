/* Program to demostrate basic functionality of cat command */
/*
 struct flock {
               ...
               short l_type;   
                            
               short l_whence;
                             
               off_t l_start;
               off_t l_len; 
               pid_t l_pid;
                          
               ...
           };

*/

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
	struct flock lock;
	memset (&lock, 0, sizeof(lock));
	
	if (argc != 2) {
		printf("Usage: %s file_name\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	//if ((fd = open(argv[1], O_RDONLY)) == -1) {
	if ((fd = open(argv[1], O_RDWR)) == -1) {
		printf("Error %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
//	lock.l_type = F_SETLK;
//	lock.l_type = F_RDLCK;
	lock.l_type = F_WRLCK;
	
//	if ((fcntl(fd, F_SETLKW, &lock)) == -1) {
//		printf("- Error %m\n");
//		exit(EXIT_FAILURE);
//	}


	getchar();
	
	
	
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
	
