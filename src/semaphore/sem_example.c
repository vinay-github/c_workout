#define _GNU_SOURCE
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>
#include <stdlib.h>

union semun {
	int              val;    /* Value for SETVAL */
	struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
    unsigned short  *array;  /* Array for GETALL, SETALL */
    struct seminfo  *__buf;  /* Buffer for IPC_INFO */
};

int main(int argc, char *argv[]) {
	int semid, semnum, semflag;
	union semun sem;
	struct sembuf sops;

	if (argc != 3) {
		printf("Usage: %s <semid> <semnum>\n", program_invocation_short_name);
		exit(EXIT_FAILURE);
	}

	semid 	= atoi(argv[1]);
	semnum 	= atoi(argv[2]);

	// int semctl(int semid, int semnum, int cmd, ...);
/*
	semflag = (SETVAL);
	sem.val = 0;
	
	if ((semctl(semid, semnum, semflag, &sem)) == -1) {
		printf("semctl failed - %m\n");
		exit(EXIT_FAILURE);
	}
*/
	 /* Code to set semid omitted */

     sops.sem_num = 0;        /* Operate on semaphore 0 */
     sops.sem_op = -1;         /* Wait for value to equal 0 */
     sops.sem_flg = 0;

	printf("Requesting for semaphore\n");
	if ((semop(semid, &sops, 1)) == -1) {
		printf("semop failed - %m\n");
		exit(EXIT_FAILURE);
	}
	printf("Semop successful\n");

	return 0;
}
