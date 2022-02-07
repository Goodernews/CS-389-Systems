# Code for Question 5

*This is a rough documentation of the code*

To make an executable run `make update_locations`. This will make an executable which takes two command line arguments (ex `./update_locations 10 100`)

To clean run `make clean`

There is a header file (`update_locations.hh`) which defines the type for the lists on line 8 (`typedef double vec_t;`) changing this changes the type of the list. `make clean` must be run in order to rebuild with the new type as `update_locations.hh` is not tracked by the makefile

