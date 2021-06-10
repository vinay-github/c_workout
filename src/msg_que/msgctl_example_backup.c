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
	int msqid, cmd, ret, max_msgid, msgid;
	struct msqid_ds msqid_stat;
	struct msginfo msginfo_buf;
	struct passwd *msg_passwd;

	if (argc != 2) {
		printf("Usage: %s <msqid>\n", program_invocation_short_name);
		exit(EXIT_FAILURE);
	}

	msqid 	= atoi(argv[1]);
	cmd		= ( MSG_INFO );

	ret = msgctl(msqid, cmd, (struct msqid_ds *) &msginfo_buf);
	if (ret == -1) {
		printf("msgctl() failed - %m\n");
		exit(EXIT_FAILURE);
	}

	max_msgid = ret;
	cmd = ( MSG_STAT );
	for(msgid = 0; msgid <= max_msgid; msgid++) {
		ret = msgctl(msgid, cmd, &msqid_stat);
		if (ret == -1) {
			if (errno != EINVAL && errno != EACCES) {
				printf("msgctl() failed - %m\n");
				exit(EXIT_FAILURE);
			}
			continue;
		}
		msg_passwd = getpwuid(msqid_stat.msg_perm.uid);
		printf("key = %#x, msgid = %d msg_qbytes=%ld msg_qnum=%ld user=%s mode=%o\n",msqid_stat.msg_perm.__key, msgid, msqid_stat.msg_qbytes, msqid_stat.msg_qnum, msg_passwd->pw_name, msqid_stat.msg_perm.mode);
	}

	return 0;
}
