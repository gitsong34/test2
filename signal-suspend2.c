#include <stdio.h>
#include <unistd.h>
#include <signal.h>
int main(void) {
	sigset_t sigset;
	sigfillset(&sigset);
	sigdelset(&sigset, SIGUSR1);
	printf("PID: %d, waiting for only SIGUSR1\n", getpid());
	sigsuspend(&sigset);
	return 0;
}
