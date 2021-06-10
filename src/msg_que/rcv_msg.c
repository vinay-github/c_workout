#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MTEXT_SIZE	128

int main(int argc, char *argv[]) {
	int 		mid, msgflg;
	ssize_t 	nbytes;
	long		msgtyp = 0; 
	
	struct msgbuf *msg;
	
	if ((argc < 2) || (argc > 3)) {
		printf("Usage: %s <msgid> [mtype]\n", program_invocation_short_name);
		exit(EXIT_FAILURE);
	}

	mid = atoi(argv[1]);

	if (argc == 3) {
		msgtyp = atol(argv[2]);
	}

	msg = malloc(MTEXT_SIZE);
	msgflg = ( IPC_NOWAIT | MSG_EXCEPT );
	//msgflg = ( MSG_NOERROR | IPC_NOWAIT );

	while (1) {	
		nbytes = msgrcv(mid, (void *) msg, (size_t) MTEXT_SIZE, msgtyp, msgflg);
		if (nbytes == -1) {
			printf("msgrcv failed (%m)\n");
			exit(EXIT_FAILURE);
		}
		printf("Type=%ld\nData=%s\n", msg->mtype, msg->mtext);
	}

	printf("Type=%ld\nData=%s\n", msg->mtype, msg->mtext);

	free(msg);
	return 0;
} 
	
	
