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
	long	mtype;
	int 	to;
	int 	from;
	char 	message[MTEXT_SIZE];
};

int main(int argc, char *argv[]) {
	int 		mid, msgflg, my_id;
	long		msgtyp = 0;
	ssize_t		nbytes;
	pid_t		p;
	
	struct data 	data_st;
	
	if ((argc != 3)) {
		printf("Usage: %s <msgid> <id(int)>\n", program_invocation_short_name);
		exit(EXIT_FAILURE);
	}

	mid = atoi(argv[1]);

	if (argc == 3) {
		my_id = atoi(argv[2]);
	}

	p = fork();
	if (p < 0) {
		printf("Fork failed %m.\n");
		exit(EXIT_FAILURE);
	}
	else if (p > 0) {
		msgflg = 0;
		//msgflg = (MSG_COPY);
		while (1) {
			memset(data_st.message, 0, MTEXT_SIZE);		
			
			nbytes = msgrcv(mid, (struct data *) &data_st, sizeof(data_st) - sizeof(long), msgtyp, msgflg);
			if (nbytes == -1) {
				printf("msgrcv failed (%m)\n");
				exit(EXIT_FAILURE);
			}
			
			if (data_st.to == my_id) {
				printf("%d: %s\n", data_st.from, data_st.message);
			}
			else {
				if ((msgsnd(mid, (struct msgbuf *) &data_st, sizeof(data_st)-sizeof(long), msgflg)) == (int) -1) {
          			printf("msgsnd failed %m\n");
					exit(EXIT_FAILURE);
	    		}
			}
		}
	} 
	else {
		msgflg = 0;
		while (1) {
			memset(data_st.message, 0, MTEXT_SIZE);		

			data_st.from = my_id;
			scanf("%d%s", &data_st.to, data_st.message); 
			if ((msgsnd(mid, (struct msgbuf *) &data_st, sizeof(data_st)-sizeof(long), msgflg)) == (int) -1) {
          		printf("msgsnd failed %m\n");
				exit(EXIT_FAILURE);
	    	}
		}
	}

	return 0;
} 
	
	
