CXX=gcc
CXXFLAGS=-Wall -Werror -Wextra -pedantic -O0 -g
LDFLAGS=$(CXXFLAGS)
OBJ=$(SRC:.cc=.o)
all:
	Benchmark


Benchmark: Benchmark.o
	$(CXX) $(LDFLAGS) -o $@ $^ -lm


plot:
	gnuplot -p plot.gnuplot

run_benchmark:
	make Benchmark
	./Benchmark 2500 2 1073741824 
	make plot

%.o: %.cc %.hh
	$(CXX) $(CXXFLAGS) $(OPTFLAGS) -c -o $@ $< -lm


clean:
	rm -rf *.o *.csv *.png Benchmark
