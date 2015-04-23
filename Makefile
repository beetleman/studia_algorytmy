CFLAGS = -Wall -ansi # tutaj można dodawać inne flagi kompilatora
LIBS = -lm # tutaj można dodawać biblioteki

all: main

clean:
	rm -fr algorytmy.o main

algorytmy.o: 
	$(CC) $(CFLAGS) algorytmy.c -o algorytmy.o -c $(LIBS)

main: algorytmy.o
	$(CC) $(CFLAGS) algorytmy.o main.c -o main $(LIBS) 

test: clean main
	./main
