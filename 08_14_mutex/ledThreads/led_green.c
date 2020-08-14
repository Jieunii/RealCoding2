#include "led.h"

void * led_green_task(void *arg)
{
	int i;
	pinMode(LED_GREEN, OUTPUT);
	
	for(i=0; i<(int)arg; i++) {
		digitalWrite(LED_GREEN, HIGH);
        printf("GREEN ON!\n");
		sleep(2);
		digitalWrite(LED_GREEN, LOW);
        printf("GREEN OFF!\n");
		sleep(2);
	}
	pthread_exit(arg);
}