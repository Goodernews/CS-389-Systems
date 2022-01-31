# HW 2

This folder contains work for "Binary and C Intro Assignment (Learning)"

## Code

This section covers question 4 which asks:

> Write C code that generates a list of random integers and computes the mean (as a real number). 
> Your program should take as input two parameters, the length of the list, and a seed to generate the random numbers.
It should print out the list of integers and the calculated mean. 
Submit your code, as well as the makefile you used to compile it.

### Building 

- To compile the code run `make rand_mean` 
- To clean the workspace run `make clean` 

### Executing

The file takes two arguments (and has no exception handling implemented). To run execute `./rand_mean [number of elements] [seed]` from the command line.

Ex: `./rand_mean 2 1234`

`> The mean value of the array is: 472354376.500`
