/*
NAME
       msgctl - System V message control operations

SYNOPSIS
       #include <sys/types.h>
       #include <sys/ipc.h>
       #include <sys/msg.h>

       int msgctl(int msqid, int cmd, struct msqid_ds *buf);

*/
#define _GNU_SOURCE

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <pwd.h>

int main(int argc, char *argv[]) {
	int msqid, cmd, ret, max_msgid, msgid, mode;
	struct msqid_ds msqid_stat;
	struct msginfo msginfo_buf;
	struct passwd *msg_passwd;

	if (argc != 3) {
		printf("Usage: %s <msqid> <permissions>\n", program_invocation_short_name);
		exit(EXIT_FAILURE);
	}

	msqid 	= atoi(argv[1]);
	mode	= atoi(argv[2]);
	cmd		= ( IPC_STAT );

	ret = msgctl(msqid, cmd, &msqid_stat);
	if (ret == -1) {
		printf("msgctl() failed - %m\n");
		exit(EXIT_FAILURE);
	}
	printf("Mode = %o\n", msqid_stat.msg_perm.mode);

	cmd		= (IPC_SET);
	msqid_stat.msg_perm.mode = mode;

	ret = msgctl(msqid, cmd, &msqid_stat);	 
	if (ret == -1) {
		printf("msgctl() failed - %m\n");
		exit(EXIT_FAILURE);
	}

	printf("**Mode = %o\n", msqid_stat.msg_perm.mode);
	
	return 0;
}
