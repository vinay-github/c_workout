#define _GNU_SOURCE

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(int argc, char *argv[]) {
	int option;

	if (( option = getopt(argc, argv, "hi:")) != -1) {
		switch(option) {
			case 'h':
				printf("Usage: %s <-i shmid>\n", program_invocation_short_name);
				exit(EXIT_SUCCESS);
			case 'i':
				shmid = strtol(optarg, NULL, 0);
				if ( shmid == LONG_MIN || shmid == LONG_MAX) {
					printf("strtol failed - %m\n", shmid);
					exit(EXIT_FAILURE);
				}
				shmid_flag = 1;
				break;
			case ':':
				printf("Missing argument: %c\n", optopt);
				exit(EXIT_FAILURE);
			case '?':
				printf("Invalid argument %c\n", optopt);
				exit(EXIT_FAILURE);
		}
	}


