#include <stdio.h>
#include <signal.h>
#include <unistd.h>
struct sigaction act_new;
struct sigaction act_old;
void sigint_handler(int signo) {
	printf("Ctrl-C 키를 눌루셨죠!!\n");
	printf("또 누르시면 종료됩니다.\n");
	sigaction(SIGINT, &act_old, NULL);
}
int main(void) {
	act_new.sa_handler = sigint_handler; 
	sigemptyset(&act_new.sa_mask); 

	sigaction(SIGINT, &act_new, &act_old);
	while(1) {
		printf("sigaction\n");
		sleep(1);
	}
	return(0);
}
