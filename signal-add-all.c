#include <stdio.h>
#include <signal.h>
int main(void) {
	sigset_t set;
	sigfillset(&set); // 모든 시그널들을 등록

	switch(sigismember(&set, SIGINT)) {
		case 1 : printf("SIGINT는 포함되어 있습니다.\n");
				 break;
		case 0 : printf("SIGINT는 없습니다.\n");
				 break;
		default : printf("sigismember() 호출에 실패했습니다.\n");
	}
	return 0;
}
