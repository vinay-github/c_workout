#define _GNU_SOURCE         /* See feature_test_macros(7) */
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

int main(int argc, char *argv[]) {

	key_t key;
	int 	mid, msgflg;
	long 	mtype;
	size_t 	len;
	char 	*mtext = "default text";
	struct 	msgbuf *msg;


	if ( argc < 2 ||  argc > 4 ) {
		printf("Usage: %s <msgid> [mtype] [msg] \n", program_invocation_short_name);
		exit(EXIT_FAILURE);
	}

	mid = atoi(argv[1]);
	mtype = (argc >= 3) ? atol(argv[2]) : 0L;
	
	if (argc >=4 ) {
		mtext = argv[3];
	}

	len = strlen(mtext);
	msg = malloc(len + sizeof(long));
	
	msg->mtype = mtype;
	strncpy(msg->mtext, mtext, len);
	
	msgflg = 0;
	
	if ((msgsnd(mid, msg, len, msgflg)) == (int) -1) {
		printf("msgsnd failed %m\n");
		exit(EXIT_FAILURE);
	}

	free(msg);
	
	return 0;
}
