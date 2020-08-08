SRCS := func.c main.c
OBJS := $(SRCS:.c=.o)
CC := gcc
CFLAGS = -Wall -g

test : $(OBJS)
	$(CC) -o $@ $^

#dummy target
clean :
	-rm $(OBJS)
	rm test

dep :
	gccmakedep $(SRCS)
