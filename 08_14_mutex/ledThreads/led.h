#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wiringPi.h>
#include <pthread.h>

#define LED_RED 1
#define LED_GREEN 4
#define LED_YELLOW 5

void* led_yellow_task(void* args);
void* led_green_task(void* args);