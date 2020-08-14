#include "led.h"

void led_red_task()
{
	pinMode(LED_RED, OUTPUT);
	
	for(int i=0; i<10; i++) {
		digitalWrite(LED_RED, HIGH);
        printf("RED ON!\n");
		sleep(1);
		digitalWrite(LED_RED, LOW);
        printf("RED OFF!\n");
		sleep(1);
	}
}

int main(int argc, char *argv[])
{
	int gno;
    int count;
    pthread_t tid_Y, tid_G;
	
	if(argc < 2) {
        wiringPiSetup();
	    led_red_task();
	}
    else{
        gno = atoi(argv[1]);
        count = atoi(argv[2]);

        wiringPiSetup();
        
        if (gno == 1) {
            led_red_task();
            if (pthread_create(&tid_G, NULL, led_green_task, (void*)count) != 0)
            {
                perror("pthread_create");
                exit(1);
            }
        } else if (gno == 2) {
            led_red_task();
            if (pthread_create(&tid_Y, NULL, led_yellow_task, (void*)count) != 0)
            {
                perror("pthread_create");
                exit(1);
            }
        } else if(gno == 3){
            led_red_task();
            if (pthread_create(&tid_Y, NULL, led_yellow_task, (void*)count) != 0)
            {
                perror("pthread_create");
                exit(1);
            }
            if (pthread_create(&tid_G, NULL, led_green_task, (void*)count) != 0)
            {
                perror("pthread_create");
                exit(1);
            }
        }
    }
    pthread_exit(NULL);
    return 0;
}




