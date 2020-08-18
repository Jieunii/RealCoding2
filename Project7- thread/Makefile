SRCS := thread.c
OBJS := $(SRCS:.c=.o)
CC := gcc
#컴파일 옵션
CFLAGS = -Wall -g
#linking 옵션
LDFLAGS = -lpthread

threadTest : $(OBJS)
	$(CC) -o $@ $^ ${LDFLAGS}

# dummy target
clean : 
	-rm $(OBJS)
	-rm threadTest
dep :
	gccmakedep ${SRCS}