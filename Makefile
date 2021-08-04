CFLAGS=-Wall -Wextra -std=c11 -pedantic

la.o: la.h
	$(CC) $(CFLAGS) -DLA_IMPLEMENTATION -x c -c la.h

la.h: lag
	./lag > la.h

lag: lag.c
	$(CC) $(CFLAGS) -o lag lag.c
