#!/usr/bin/gnuplot
set terminal png size 800,480 enhanced font 'Arial, 16'
set output 'exp1.png'

set style line 1 linecolor rgb 'red' linetype 1 linewidth 2
set style line 2 linecolor rgb 'blue' linetype 1 linewidth 2

set border linewidth 1
set key top left
set grid
set mytics 0
set format y "%.6f"
set xlabel "Количество элементов" font "Arial, 16"
set format x "%.0f" 
set ylabel "Время выполнения в секундах" font "Arial, 16"
set xtics 100000 font "Arial, 12"
set ytics font "Arial, 12"
set rmargin 4
set tmargin 2
set mxtics

plot "1bstree_lookup_average.dat" using 1:2 title "BST Lookup (average)" with linespoints ls 1,\
     "1hash_lookup_average.dat" using 1:2 title "HASHTAB Lookup (average)" with linespoints ls 2, 
     