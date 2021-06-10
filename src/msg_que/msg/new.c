#define _GNU_SOURCE         /* See feature_test_macros(7) */
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct send_info {
	long mtype;
	int to;
};

int main(int argc, char *argv[]) {

	int 	mid, msgflg;
	char 	*mtext;
	struct 	send_info msg;

	if ( argc != 4 ) {
		printf("Usage: %s <msgid> <to> <msg> \n", program_invocation_short_name);
		exit(EXIT_FAILURE);
	}

	mid = atoi(argv[1]);
	
	if (argc >=4 ) {
		mtext = argv[3];
	}
	printf("msg = %s\n", mtext);

	msg.mtype = 0;
	msg.to	= atoi(argv[2]);
	
	msgflg = 0;
	
	if ((msgsnd(mid, (struct msgbuf *)&msg, sizeof(msg)-sizeof(long), msgflg)) == (int) -1) {
		printf("msgsnd failed %m\n");
		exit(EXIT_FAILURE);
	}

	return 0;
}
