#define _GNU_SOURCE         /* See feature_test_macros(7) */
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct data {
	long mtype;
	int to;
	int from;
	char message[40];
};

int main(int argc, char *argv[]) {

	int 	mid, msgflg;
	long 	mtype = 0;
	size_t 	len;
	char 	*mtext = "default text";
	struct	data	data_st;

	if ( argc != 4 ) {
		printf("Usage: %s <msgid> <to> <msg> \n", program_invocation_short_name);
		exit(EXIT_FAILURE);
	}

	mid = atoi(argv[1]);
	
	if (argc >=4 ) {
		mtext = argv[3];
	}

	data_st.mtype = mtype;
	data_st.to = atoi(argv[2]);
	data_st.from = 14;
	strcpy(data_st.message, mtext);
	len = sizeof(data_st) - sizeof(data_st.mtype);
	msgflg = 0;

	if ((msgsnd(mid, (struct msgbuf *) &data_st, len, msgflg)) == (int) -1) {
		printf("msgsnd failed %m\n");
		exit(EXIT_FAILURE);
	}
	
	return 0;
}
