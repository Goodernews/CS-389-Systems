#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<atomic>

using namespace std;

int Centralized(int num_threads); // implementation

void* centralized_barrier(void *Arguments);

struct args {
    atomic_int Counter;
    bool Sense;
    int Nthreads;
};
