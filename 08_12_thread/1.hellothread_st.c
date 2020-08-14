#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int d1=10, d2;

void * hello_thread(void *arg)
{
	int i=200;
	
	printf("Hello_Thread Start(d1:%d, d2:%d, i:%d)!!\n", d1,d2,i);
	for(i=1; i<=(int)arg; i++) {
		printf("Hello_Thread_%d!!\n", i);
		d1++;
		d2++;
		sleep(1);
	}
	printf("Hello_Thread End(d1:%d, d2:%d, i:%d)!!\n", d1,d2,i);
	//return arg;
	pthread_exit(arg);
}

int main(void)
{
	pthread_t tid;
	int status;
	int i=100;
	pthread_attr_t attr; //속성은 우리가 채우는 것이다. 값을 할당하고 넘기는 것이 의미가 있다.
	
	printf("Main_Thread Start(d1:%d, d2:%d, i:%d)!!\n", d1,d2,i);
	status = pthread_create(&tid, NULL, hello_thread, (void*)15);//주소를 넘긴다. 속성을 받지 않을 거면 NULL. 
	if(status != 0) {
		perror("thread create");
		exit(1);
	}	
	
	for(i=1; i<=5; i++) {
		printf("Main_Thread_%d!!\n", i);
		sleep(1);
	}
	printf("Main_Thread End(d1:%d, d2:%d, i:%d)!!\n", d1,d2,i);
	pthread_exit(NULL); //커널에게 내 메모리를 access하는 녀석이 있다면 메모리를 해지하지 말아라.
    return 0;
}