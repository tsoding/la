CFLAGS=-Wall -Wextra -pedantic

all: la.c.o la.cxx.o ball

ball: examples/ball.c la.h
	cd examples && $(CC) $(CFLAGS) -std=c11 -ggdb -o ../ball ball.c -I.. -lm

la.cxx.o: la.h
	$(CC) $(CFLAGS) -DLA_IMPLEMENTATION -x c++ -o la.cxx.o -c la.h

la.c.o: la.h
	$(CC) $(CFLAGS) -std=c99 -DLA_IMPLEMENTATION -x c -o la.c.o -c la.h

la.h: lag
	./lag > la.h

lag: src/lag.c
	$(CC) $(CFLAGS) -std=c11 -pedantic -ggdb -D_GNU_SOURCE -o lag src/lag.c -I thirdparty -lrt
