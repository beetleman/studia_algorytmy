set autoscale
unset log
unset label
set xtic auto
set ytic auto
set key autotitle columnhead
set xlabel 'Liczba elementów w tablicy'
set ylabel 'Czas wykonania [s]'
set key left top
set datafile separator ','

d_dir = 'data/'
d_ext = '.csv'

p_terminals = 'png svg'

random_csv = d_dir.'random'.d_ext
sorted_csv = d_dir.'sorted'.d_ext
reverse_sorted_csv = d_dir.'reverse_sorted'.d_ext


do for [i=1:words(p_terminals)] {

p_terminal = word(p_terminals, i)
p_ext = '.'.p_terminal
p_dir = 'plots/'.p_terminal.'/'

set terminal p_terminal enhanced background rgb 'white'


set output p_dir.'random'.p_ext
set title 'Dane losowe'

plot random_csv using 1:2 with points pt 1 lc rgb "red", \
     random_csv using 1:3 with points pt 1 lc rgb "black", \
     random_csv using 1:4 with points pt 1 lc rgb "green", \
     random_csv using 1:5 with points pt 1 lc rgb "purple", \
     random_csv using 1:6 with points pt 1 lc rgb "blue", \
     random_csv using 1:7 with points pt 1 lc rgb "pink"


set output p_dir.'random_fast'.p_ext
set title 'Dane losowe, najszybsze algorytmy'

plot random_csv using 1:4 with points pt 1 lc rgb "green", \
     random_csv using 1:5 with points pt 1 lc rgb "purple", \
     random_csv using 1:6 with points pt 1 lc rgb "blue", \
     random_csv using 1:7 with points pt 1 lc rgb "pink"


set output p_dir.'sorted'.p_ext
set title 'Dane posortowane'

plot sorted_csv using 1:2 with points pt 1 lc rgb "red", \
     sorted_csv using 1:3 with points pt 1 lc rgb "black", \
     sorted_csv using 1:4 with points pt 1 lc rgb "green", \
     sorted_csv using 1:5 with points pt 1 lc rgb "purple", \
     sorted_csv using 1:6 with points pt 1 lc rgb "blue", \
     sorted_csv using 1:7 with points pt 1 lc rgb "pink"


set output p_dir.'sorted_fast'.p_ext
set title 'Dane posortowane, najszybsze algorytmy'

plot sorted_csv using 1:2 with points pt 1 lc rgb "red", \
     sorted_csv using 1:4 with points pt 1 lc rgb "green", \
     sorted_csv using 1:6 with points pt 1 lc rgb "blue", \
     sorted_csv using 1:7 with points pt 1 lc rgb "pink"


set output p_dir.'reverse_sorted'.p_ext
set title 'Dane odwrotnie posortowane'

plot reverse_sorted_csv using 1:2 with points pt 1 lc rgb "red", \
     reverse_sorted_csv using 1:3 with points pt 1 lc rgb "black", \
     reverse_sorted_csv using 1:4 with points pt 1 lc rgb "green", \
     reverse_sorted_csv using 1:5 with points pt 1 lc rgb "purple", \
     reverse_sorted_csv using 1:6 with points pt 1 lc rgb "blue", \
     reverse_sorted_csv using 1:7 with points pt 1 lc rgb "pink"


set output p_dir.'reverse_sorted_fast'.p_ext
set title 'Dane odwrotnie posortowane, najszybsze algorytmy'

plot reverse_sorted_csv using 1:4 with points pt 1 lc rgb "green", \
     reverse_sorted_csv using 1:6 with points pt 1 lc rgb "blue", \
     reverse_sorted_csv using 1:7 with points pt 1 lc rgb "pink"


set output p_dir.'insert'.p_ext
set title 'Sortowanie przez wstawianie'

plot reverse_sorted_csv using 1:2 title 'odwrotnie posortowane' with points pt 1 lc rgb "red", \
     sorted_csv using 1:2 title 'posortowana' with points pt 1 lc rgb "black", \
     random_csv using 1:2 title 'losowe' with points pt 1 lc rgb "green", \


set output p_dir.'select'.p_ext
set title 'Sortowanie przez wybieranie'

plot reverse_sorted_csv using 1:3 title 'odwrotnie posortowane' with points pt 1 lc rgb "red", \
     sorted_csv using 1:3 title 'posortowana' with points pt 1 lc rgb "black", \
     random_csv using 1:3 title 'losowe' with points pt 1 lc rgb "green", \


set output p_dir.'merge'.p_ext
set title 'Sortowanie przez scalanie'

plot reverse_sorted_csv using 1:4 title 'odwrotnie posortowane' with points pt 1 lc rgb "red", \
     sorted_csv using 1:4 title 'posortowana' with points pt 1 lc rgb "black", \
     random_csv using 1:4 title 'losowe' with points pt 1 lc rgb "green", \


set output p_dir.'qsort'.p_ext
set title 'Sortowanie szybkie'

plot reverse_sorted_csv using 1:5 title 'odwrotnie posortowane' with points pt 1 lc rgb "red", \
     sorted_csv using 1:5 title 'posortowana' with points pt 1 lc rgb "black", \
     random_csv using 1:5 title 'losowe' with points pt 1 lc rgb "green", \


set output p_dir.'qsort_randomized'.p_ext
set title 'Sortowanie szybkie z losowym pivotem'

plot reverse_sorted_csv using 1:6 title 'odwrotnie posortowane' with points pt 1 lc rgb "red", \
     sorted_csv using 1:6 title 'posortowana' with points pt 1 lc rgb "black", \
     random_csv using 1:6 title 'losowe' with points pt 1 lc rgb "green", \


set output p_dir.'count'.p_ext
set title 'Sortowanie przez zliczanie'

plot reverse_sorted_csv using 1:7 title 'odwrotnie posortowane' with points pt 1 lc rgb "red", \
     sorted_csv using 1:7 title 'posortowana' with points pt 1 lc rgb "black", \
     random_csv using 1:7 title 'losowe' with points pt 1 lc rgb "green", \

}
