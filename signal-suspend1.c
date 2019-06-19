#include <stdio.h>
#include <unistd.h>
#include <signal.h>
int main(void) {
	sigset_t sigset;
	sigemptyset(&sigset);
	sigaddset(&sigset, SIGINT);
	printf("PID: %d, waiting for any signal except SIGINT\n", getpid());
	sigsuspend(&sigset);
	return 0;
}
