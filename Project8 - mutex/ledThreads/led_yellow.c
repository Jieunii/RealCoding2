#include "led.h"

void * led_yellow_task(void *arg)
{
	int i;
	pinMode(LED_YELLOW, OUTPUT);
	
	for(i=0; i<(int)arg; i++) {
		digitalWrite(LED_YELLOW, HIGH);
        printf("YELLOW ON!\n");
		sleep(3);
		digitalWrite(LED_YELLOW, LOW);
        printf("YELLOW OFF!\n");
		sleep(3);
	}
    pthread_exit(arg);

}