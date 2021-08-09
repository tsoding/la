CFLAGS=-Wall -Wextra -pedantic

all: la.c.o la.cxx.o ball

ball: ball.c la.h
	$(CC) $(CFLAGS) -std=c11 -ggdb -o ball ball.c -lm

la.cxx.o: la.h
	$(CC) $(CFLAGS) -DLA_IMPLEMENTATION -x c++ -o la.cxx.o -c la.h

la.c.o: la.h
	$(CC) $(CFLAGS) -std=c99 -DLA_IMPLEMENTATION -x c -o la.c.o -c la.h

la.h: lag
	./lag > la.h

lag: lag.c
	$(CC) $(CFLAGS) -std=c11 -ggdb -o lag lag.c
