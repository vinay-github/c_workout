#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define FILESIZE (0x100000)

int main(int argc, char *argv[])
{
    int i;
    int fd;
    int *map;

    //fd = open("/dev/zero", O_RDONLY);
    fd = open("/tmp/sample.txt", O_RDONLY);
    if (fd == -1) {
		printf("Error opening file for reading");
		exit(EXIT_FAILURE);
    }

//    map = mmap(NULL, FILESIZE, PROT_READ, MAP_SHARED, fd, 0);
    map = mmap(NULL, 1073741824, PROT_READ, MAP_SHARED, fd, 0);

    if (map == MAP_FAILED) {
		close(fd);
		printf("Error mmapping the file");
		exit(EXIT_FAILURE);
    }
    
	getchar();
    close(fd);
    return 0;
}
