set term png
set output "plot.png"
set datafile separator ','
set title "Memory access time for different sizes"
set xlabel 'Size of array (Bytes)'
set ylabel "Time to Access (Nanoseconds)"
set format x '%.0s%cB'
set logscale x 2

#f(x) = m*x + b # best fit
#fit f(x) "output.csv" using 1:2 via m,b

#set style boxplot outliers pointtype 7
#set style data boxplot



set key autotitle columnhead #ignore colun headers

# set jitter overlap 1  spread 0.2  wrap 0 # jitter 

plot "output.csv" using 1:2 w points#, f(x) 

