#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

short int scores[30]={0};

void * sthread1(void *arg)
{
	int sum=0;
    float avg;
	printf("====sthread1 start====\n");
	for(int i=0; i<=(int)arg; i++) {
		sum += scores[i];
	}
    avg = sum / 30.0;
    printf("합 : %d, 평균 : %f\n", sum, avg);
	printf("====sthread1 end====\n");

	pthread_exit(arg);
}

void * sthread2(void *arg)
{
    int key, i, j;

	printf("====sthread2 start====\n");
	for(i=1;i<(int)arg;i++)
	{
		key = scores[i];
		for(j=i-1;j>=0 && scores[j]<key;j--)
		{
			scores[j+1] = scores[j];
		}
		scores[j+1] = key;
	}

    for(i=0;i<(int)arg;i++){
        printf("%2d등 : %d\n", i+1, scores[i]);
    }
	printf("====sthread2 end====\n");

	pthread_exit(arg);
}

int main(void)
{
	pthread_t tid1, tid2;
	int status1, status2;
	pthread_attr_t attr;
	
    for(int i = 0;i<30;i++)
    {
        scanf("%hd", &scores[i]);
    }

    printf("성적 sample\n");
    for(int i = 0;i<30;i++)
    {
        printf("%3hd\n", scores[i]);
    }

    printf("Main start!\n");
	status1 = pthread_create(&tid1, NULL, sthread1, (void*)30);
	if(status1 != 0) {
		perror("thread1 create");
		exit(1);
	}

    status2 = pthread_create(&tid2, NULL, sthread2, (void*)30);
    if(status2 != 0) {
		perror("thread2 create");
		exit(1);
	}	
    printf("Main end!\n");

	pthread_exit(NULL);
    return 0;
}