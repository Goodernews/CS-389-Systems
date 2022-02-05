CXX=gcc
CXXFLAGS=-Wall -Werror -Wextra -pedantic -O0 -g
LDFLAGS=$(CXXFLAGS)
OBJ=$(SRC:.cc=.o)
all:
	update_locations


update_locations: update_locations.o
	$(CXX) $(LDFLAGS) -o $@ $^


%.o: %.cc %.hh
	$(CXX) $(CXXFLAGS) $(OPTFLAGS) -c -o $@ $<

clean:
	rm -rf *.o update_locations
