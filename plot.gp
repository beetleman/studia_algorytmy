set terminal svg
set output 'plot.svg'

set autoscale
unset log
unset label
set xtic auto
set ytic auto
set title "Algorytmy sortowania"
set xlabel "Liczba elementow w tablicy"
set ylabel "Czas wykonania [CPU]"

plot "plot.data" using 1:2 title 'przez wstawianie' with points pt 1, \
     "plot.data" using 1:3 title 'przez wybieranie' with points pt 1, \
     "plot.data" using 1:4 title 'przez scalanie' with points pt 1, \
     "plot.data" using 1:5 title 'szybkie' with points pt 1, \
     "plot.data" using 1:6 title 'szybkie losowy piwot' with points pt 1
