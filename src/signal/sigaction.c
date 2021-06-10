#include <stdio.h>
#include <signal.h>
#include <error.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

#ifdef MYREF
 		#include <signal.h>

       	int sigaction(int signum, const struct sigaction *act,
                     struct sigaction *oldact);
		siginfo_t {
               int      si_signo;     /* Signal number */
               int      si_errno;     /* An errno value */
               int      si_code;      /* Signal code */
               int      si_trapno;    /* Trap number that caused
                                         hardware-generated signal
                                         (unused on most architectures) */
               pid_t    si_pid;       /* Sending process ID */
               uid_t    si_uid;       /* Real user ID of sending process */
               int      si_status;    /* Exit value or signal */
               clock_t  si_utime;     /* User time consumed */
               clock_t  si_stime;     /* System time consumed */
               sigval_t si_value;     /* Signal value */
               int      si_int;       /* POSIX.1b signal */
               void    *si_ptr;       /* POSIX.1b signal */
               int      si_overrun;   /* Timer overrun count;
                                         POSIX.1b timers */
               int      si_timerid;   /* Timer ID; POSIX.1b timers */
               void    *si_addr;      /* Memory location which caused fault */
               long     si_band;      /* Band event (was int in
                                         glibc 2.3.2 and earlier) */
               int      si_fd;        /* File descriptor */
               short    si_addr_lsb;  /* Least significant bit of address
                                         (since Linux 2.6.32) */
               void    *si_lower;     /* Lower bound when address violation
                                         occurred (since Linux 3.19) */
               void    *si_upper;     /* Upper bound when address violation
                                         occurred (since Linux 3.19) */
               int      si_pkey;      /* Protection key on PTE that caused
                                         fault (since Linux 4.6) */
               void    *si_call_addr; /* Address of system call instruction
                                         (since Linux 3.5) */
               int      si_syscall;   /* Number of attempted system call
                                         (since Linux 3.5) */
               unsigned int si_arch;  /* Architecture of attempted system call
                                         (since Linux 3.5) */
           }


#endif

void my_signal_handler(int signal, siginfo_t *siginfo, void *unused) {
	printf("This is my_signal_handler()\n");
	printf("Signal number %d\n", siginfo->si_signo);
	printf("Error number %d\n", siginfo->si_errno);
	printf("Signal code %d\n", siginfo->si_code);
//	printf("Trap number that caused %d\n", siginfo->si_trapno);
	printf("Sending process ID %d", siginfo->si_pid);
	printf("Real user ID of sending process %d\n", siginfo->si_uid);
	printf("Exit value or signal %d\n", siginfo->si_status);
}

int main() {
	int status;
	struct sigaction act;
	struct sigaction oldact;

	memset(&act, '\0', sizeof(act));
	memset(&oldact, '\0', sizeof(oldact));

	act.sa_action 	= &my_signal_handler;
	act.sa_flags	= SA_SIGINFO;

	status = sigaction(SIGCHLD, &act, &oldact);
	if (status == -1) {
		printf("Error performing sigaction. Error: %d, %m\n", errno);
		exit(EXIT_FAILURE);
	}
	return 0;
}
