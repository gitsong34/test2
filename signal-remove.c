#include <stdio.h>
#include <signal.h>
int main(void)
{
	sigset_t set;
	sigemptyset(&set); // 시그널 집합 변수의 내용을 모두 제거
	sigaddset(&set, SIGINT); // 시그널 집합 변수에 SIGINT를 추가

	switch(sigismember(&set, SIGINT)) {
		case 1 : printf("SIGINT는 포함되어 있습니다.\n");
				 break;
		case 0 : printf("SIGINT는 없습니다.\n");
				 break;
		default : printf("sigismember() 호출에 실패했습니다.\n");
	}

	sigdelset(&set, SIGINT);
	switch(sigismember(&set, SIGINT)) {
		case 1 : printf("SIGINT는 포함되어 있습니다.\n");
				 break;
		case 0 : printf("SIGINT는 없습니다.\n");
				 break;
		default : printf("sigismember() 호출에 실패했습니다.\n");
	}
	return 0;
}
