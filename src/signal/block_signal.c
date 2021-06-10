/* Tool to block signal */

#define _GNU_SOURCE

#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

void mysignal_handler(int signal_no) {
	printf("Got the signal - %d\n", signal_no);
}

int main(int argc __attribute__((unused)), char *argv[] __attribute__((unused))) {
	sigset_t set, oldset;
	int signals_blocked, how;

	printf("UID - %d\n", getuid());
	printf("PID - %d\n", getpid());
	
	sigemptyset(&set);
	
	signals_blocked = ( SIGINT | SIGTERM );
	sigaddset(&set, signals_blocked);

	signal(SIGINT, mysignal_handler);
	signal(SIGTERM, mysignal_handler);

	printf("-----------------\n");	
	how = ( SIG_BLOCK );
	if (sigprocmask(how, &set, &oldset) == -1) {
		printf("Couldn't set mask. %m\n");
		exit(EXIT_FAILURE);
	}
	
	pause();
	pause();
	
	how = ( SIG_BLOCK );
	if (sigprocmask(how, &set, &oldset) == -1) {
		printf("Couldn't set mask. %m\n");
		exit(EXIT_FAILURE);
	}

	return 0;
}
