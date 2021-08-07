CFLAGS=-Wall -Wextra -std=c11 -pedantic

# TODO: make sure la.h compiles with -std=c89
# TODO: make sure la.h compiles with a C++ compiler
la.o: la.h
	$(CC) $(CFLAGS) -DLA_IMPLEMENTATION -x c -c la.h

la.h: lag
	./lag > la.h

lag: lag.c
	$(CC) $(CFLAGS) -ggdb -o lag lag.c
