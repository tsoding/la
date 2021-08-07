CFLAGS=-Wall -Wextra -pedantic

# TODO: make sure la.h compiles with a C++ compiler
la.o: la.h
	$(CC) $(CFLAGS) -std=c99 -DLA_IMPLEMENTATION -x c -c la.h

la.h: lag
	./lag > la.h

lag: lag.c
	$(CC) $(CFLAGS) -std=c11 -ggdb -o lag lag.c
