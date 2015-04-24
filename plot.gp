set terminal svg
set output 'plot.svg'

set autoscale
unset log
unset label
set xtic auto
set ytic auto
set title "Algorytmy sortowania"
set xlabel "Czas wykonania [s]"
set ylabel "Liczba elementow w tablicy"

plot "plot.data" using 1:2 title 'przez wstawianie' with linespoints, \
     "plot.data" using 1:3 title 'przez wybieranie' with linespoints, \
     "plot.data" using 1:4 title 'przez scalanie' with linespoints
