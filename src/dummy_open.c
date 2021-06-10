#include <stdio.h>
 #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
 #include <unistd.h>

int main() {
	int dummy01 = -1;

//	dummy01 = open("/dev/null", O_RDONLY);
	if (dummy01 < 0 ) {
		printf("Error\n");
	}

	close(dummy01);
	printf("before\n");
	close(dummy01);
	printf("after\n");
	
	return 0;
}
