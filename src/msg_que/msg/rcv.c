#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

#define MTEXT_SIZE	128

struct data {
	int to;
	int from;
	char message[MTEXT_SIZE - (sizeof(int) * 2)];
};

int main(int argc, char *argv[]) {
	int 		mid, msgflg, my_id;
	ssize_t 	nbytes;
	long		msgtyp = 0;
	pid_t		p;
	
	struct msgbuf 	*msg;
	struct data 	*data_st;
	
	if ((argc != 3)) {
		printf("Usage: %s <msgid> <id(int)>\n", program_invocation_short_name);
		exit(EXIT_FAILURE);
	}

	mid = atoi(argv[1]);

	if (argc == 3) {
		my_id = atoi(argv[2]);
	}

	msg = malloc(MTEXT_SIZE);
	//msgflg = ( MSG_NOERROR | IPC_NOWAIT );

	printf("------------------------\n");
	p = fork();
	if (p < 0) {
		printf("Fork failed %m.\n");
		exit(EXIT_FAILURE);
	}
	else if (p > 0) {
		msgflg = 0;
		while (1) {
			memset(msg, 0, MTEXT_SIZE);		
			nbytes = msgrcv(mid, (void *) msg, (size_t) MTEXT_SIZE, msgtyp, msgflg);
			if (nbytes == -1) {
				printf("msgrcv failed (%m)\n");
				exit(EXIT_FAILURE);
			}
			data_st = (struct data *) &msg->mtext;
			printf("%d: %s\n", data_st->from, data_st->message);
		}
	} 
	else {
		while (1) {
			memset(msg, 0, MTEXT_SIZE);
			msg->mtype = 0;	

/*
			printf("s------------------------\n");

			scanf("%d", &data_st->to);
			printf("s------------------------\n");
			scanf("%s", data_st->message);
			printf("s------------------------\n");
			data_st->from = my_id;
			strcpy(msg->mtext, (char *)&data_st);
*/

			data_st->to = 1;
			data_st->from = 2;
			strcpy(data_st->message, "Hiiiiii");
			strcpy(msg->mtext, (char *)&data_st);
	
			printf("to = %d from = %d msg = %s\n", data_st->to, data_st->from, data_st->message);
			
			if ((msgsnd(mid, msg, (size_t) MTEXT_SIZE, msgflg)) == (int) -1) {
          		printf("msgsnd failed %m\n");
				exit(EXIT_FAILURE);
	    	}
		}
	}

	free(msg);
	return 0;
} 
	
	
