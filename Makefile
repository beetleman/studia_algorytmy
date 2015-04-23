CFLAGS = -Wall -ansi # tutaj można dodawać inne flagi kompilatora
LIBS = -lm # tutaj można dodawać biblioteki

all: main

clean:
	rm -fr timer_lib.o algorytmy.o main

algorytmy.o: 
	$(CC) $(CFLAGS) algorytmy.c -o algorytmy.o -c $(LIBS)

timer_lib.o: 
	$(CC) $(CFLAGS) timer_lib.c -o timer_lib.o -c $(LIBS)

main: algorytmy.o timer_lib.o
	$(CC) $(CFLAGS) algorytmy.o timer_lib.o main.c -o main $(LIBS) 

test: clean main
	./main
