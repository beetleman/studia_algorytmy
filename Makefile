CFLAGS = -Wall -ansi # tutaj można dodawać inne flagi kompilatora
LIBS = -lm # tutaj można dodawać biblioteki

all: main

clean:
	rm -fr timer_lib.o algorytmy.o main sort_contest plot.data

algorytmy.o: 
	$(CC) $(CFLAGS) algorytmy.c -o algorytmy.o -c $(LIBS)

timer_lib.o: 
	$(CC) $(CFLAGS) timer_lib.c -o timer_lib.o -c $(LIBS)

main: algorytmy.o timer_lib.o
	$(CC) $(CFLAGS) algorytmy.o timer_lib.o main.c -o main $(LIBS) 

sort_contest: algorytmy.o timer_lib.o
	$(CC) $(CFLAGS) algorytmy.o timer_lib.o sort_contest.c -o sort_contest $(LIBS) 

test: clean main
	./main

run_sort_contest: clean sort_contest
	./sort_contest > plot.data
	gnuplot plot.gp
