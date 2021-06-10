#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main() {
	int ret, cret, errno;

	ret = creat("/tmp/ex/nothing.txt", S_IRWXU);
//	ret = creat("/tmp/nothing.txt", S_IRWXU);

	if ( ret == -1 ) {
		printf("errno = %m\n");
		errno=0;
		
		cret = close(ret);
		if ( cret == -1 ) {
			printf("close failed %m\n");
			errno=0;
		}
		else
			printf("close is successful\n");
		
		return -1;
	}
	else
	{
		printf("we are good\n");
		close(ret);
		
		return 0;
	}
}

