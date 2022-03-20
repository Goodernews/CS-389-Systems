#pragma once

#include<stdio.h>
#include<stdatomic.h>
#include<stdlib.h>
#include<pthread.h>
#include <stdbool.h>



int Centralized(int num_threads); // implementation

void* centralized_barrier(void *Arguments);

struct args {
    atomic_int Counter;
    bool Sense;
    int Nthreads;
};
