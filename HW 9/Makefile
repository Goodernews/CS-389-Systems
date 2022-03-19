CXX=gcc
CXXFLAGS=-Wall -Werror -Wextra -pedantic -O0 -g
LDFLAGS=$(CXXFLAGS)
OBJ=$(SRC:.C=.o)

all:
	Benchmark

Benchmark: Benchmark.o
	$(CXX) $(LDFLAGS) -o $@ $^ -O3 -lm


dissemination: dissemination.o
	$(CXX) $(LDFLAGS) -o $@ $^

centralized: centralized.o
	$(CXX) $(LDFLAGS) -o $@ $^

mcs: mcs.o
	$(CXX) $(LDFLAGS) -0 $@ $^


barrier_testing: barrier_testing.o dissemination.o centralized.o mcs.o
	$(CXX) $(LDFLAGS) -o $@ $^


barrier_performance: barrier_performance.o dissemination.o centralized.o mcs.o
	$(CXX) $(LDFLAGS) -o $@ $^

memory_plot:
	gnuplot -p plot.gnuplot

barrier_plot:
	gnuplot -p barrier_plot.gnuplot

run_benchmark:
	make Benchmark
	./Benchmark 2500 2 1073741824 
	make memory_plot

run_barrier_performance:
	make barrier_performance


run_barrier_testing:
	make barrier_testing
	./barrier_testing

%.o: %.C %.hh
	$(CXX) $(CXXFLAGS) $(OPTFLAGS) -c -o $@ $< -lm


clean:
	rm -rf *.o *.csv *.png Benchmark dissemination centralized
