#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void *t_function(void *data) {
	int id;
	id = *((int *)data);
	printf("Thread Start with %d\n", id);
	sleep(5);
	printf("Thread end\n");
}
int main(void) {
	pthread_t p_thread;
	int thr_id;
	int status;
	int a = 100;
	int i;
	printf("Before Thread\n");
	thr_id = pthread_create(&p_thread, NULL, t_function, (void *)&a);
	if (thr_id < 0) {
		perror("thread create error : ");
		exit(0);
	}

	pthread_detach(p_thread);
	for(i = 0; i < 10; i++) {
		sleep(1);
		printf("Thread detached!\n");
	}
	return 0;
}
