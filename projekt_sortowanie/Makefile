CFLAGS = -Wall -ansi -std=c99 # tutaj można dodawać inne flagi kompilatora
LIBS = -lm # tutaj można dodawać biblioteki

all: main

clean:
	rm -fr timer_lib.o algorytmy.o sort_contest.o main

algorytmy.o:
	$(CC) $(CFLAGS) algorytmy.c -o algorytmy.o -c $(LIBS)

timer_lib.o:
	$(CC) $(CFLAGS) timer_lib.c -o timer_lib.o -c $(LIBS)

sort_contest.o:
	$(CC) $(CFLAGS) sort_contest.c -o sort_contest.o -c $(LIBS)

main: sort_contest.o timer_lib.o algorytmy.o
	$(CC) $(CFLAGS) sort_contest.o timer_lib.o algorytmy.o main.c -o main $(LIBS)

run_sort_contest: clean main
	./main
	gnuplot plot.gp
