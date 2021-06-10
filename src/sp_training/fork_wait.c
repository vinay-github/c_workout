/*
 * Program to demostrate fork(), wait()
 * 
 */


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/mman.h>

int main(void) {
	pid_t childPid;
	int status;
	char *buf;
	
	buf = malloc(20);
	strcpy(buf, "Game");
	
	// Create a child process
	childPid = fork();
	printf("My PID %u\nChild's PID %u\n", getpid(), childPid);

	mlock(buf, 2048);
	
	if ( childPid == (pid_t) -1) {
		printf("fork failed error %m\n");
		return 1;
	}

	//child
	if ( childPid == (pid_t) 0) {
		printf("Child - The address of buf is %p\n", &buf);
		printf("Child - Intial content of buf is %s\n", buf);
		strcpy(buf, "Cricket");
		printf("Child - Updated content of buf is %s\n", buf);
		printf("----------------------------------------------------------\n");
		
		//exit(EXIT_SUCCESS); 
		exit(EXIT_FAILURE);
		//exit(-3);
	}

	//parent
	if ( childPid > (pid_t) 0) {
		printf("Parent - The address of buf is %p\n", &buf);
		printf("Parent - Content of buf is %s\n", buf);
		strcpy(buf, "Basketball");
		printf("Parent - Updated content of buf is %s\n", buf);
		printf("----------------------------------------------------------\n");
	}

	getchar();
	wait(&status);
	
	printf("----------------------------------------------------------\n");
	printf("At the end, content of buf is %s\n", buf);
	
	printf("Status = %d\n", WEXITSTATUS(status) );
	return 0;
}
