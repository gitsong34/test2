#include <stdio.h>
#include <signal.h>
#include <unistd.h>
void (*old_fun)(int);
void sigint_handler(int signo) {
	printf("Ctrl-C 키를 눌루셨죠!!\n");
}
int main(void) {
	old_fun = signal(SIGINT, sigint_handler);
	while(1) {
		printf("signal handler registered!\n");
		sleep(1);
	}
	return(0);
}
