#include <stdio.h>
#include <unistd.h>
#include <signal.h>
int main(void) {
	sigset_t sigset;
	int ndx;
	sigemptyset(&sigset);
	sigaddset(&sigset, SIGINT);
	sigprocmask(SIG_BLOCK, &sigset, NULL);

	for(ndx = 3; 0 < ndx; ndx--) {
		printf("카운트 다운 %d\n", ndx);
		sleep(1);
	}

	printf("Ctrl-C에 대한 블록을 해제합니다.\n");
	sigprocmask(SIG_UNBLOCK, &sigset, NULL);
	printf("카운트 다운 중에 Ctrl-C키를 누르셨다면, 이 문장도 출력이 안됩니다.\n");
	while(1)
		;
	return 0;
}
