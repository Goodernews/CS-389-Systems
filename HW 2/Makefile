CXX=gcc
CXXFLAGS=-Wall -Werror -Wextra -pedantic -O0 -g
LDFLAGS=$(CXXFLAGS)
OBJ=$(SRC:.cc=.o)
all:
	rand_mean

rand_mean: rand_mean.o
	$(CXX) $(LDFLAGS) -o $@ $^


%.o: %.cc %.hh
	$(CXX) $(CXXFLAGS) $(OPTFLAGS) -c -o $@ $<

clean:
	rm -rf *.o rand_mean
