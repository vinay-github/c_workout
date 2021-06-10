#include <stdio.h>
#include <sys/types.h>
 #include <unistd.h>


int main() {
	int a;

	printf("PID - %d\n", getpid());
		
	setsid();
	printf("Okay\n");
	getchar();

	return 0;
}
