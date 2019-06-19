#include <stdio.h>
#include <signal.h>

int main(void) {
	sigset_t set;
	sigemptyset(&set); 
	sigaddset(&set, SIGINT); 

	switch(sigismember(&set, SIGINT)) {
		case 1 : printf("SIGINT는 포함되어 있습니다.\n");
				 break;
		case 0 : printf("SIGINT는 없습니다.\n");
				 break;
		default : printf("sigismember() 호출에 실패했습니다.\n");
	}

	switch(sigismember(&set, SIGSYS)) {
		case 1 : printf("SIGSYS는 포함되어 있습니다.\n");
				 break;
		case 0 : printf("SIGSYS는 없습니다.\n");
				 break;
		default : printf("sigismember() 호출에 실패했습니다.\n");
	}
	return 0;
}
