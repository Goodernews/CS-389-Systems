#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<climits>



typedef unsigned int vec_t; // alias of type
vec_t max_num = UINT_MAX; // stores the max possible number of vec type

double time_exe(int size, vec_t* rand_list); // times how long it takes to get a random 

vec_t* generate_random_list(int size); // creates random list 
