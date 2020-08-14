SRCS := led_main.c led_green.c led_yellow.c
OBJS := $(SRCS:.c=.o)
CC := gcc
#컴파일 옵션
CFLAGS = -Wall -g
#linking 옵션
LDFLAGS = -lpthread -lwiringPi

led_main : $(OBJS)
	$(CC) -o $@ $^ ${LDFLAGS}

# dummy target
clean : 
	-rm $(OBJS)
	-rm led_main
dep :
	gccmakedep ${SRCS}