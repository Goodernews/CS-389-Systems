#pragma once

#include<stdio.h>
#include<stdatomic.h>
#include<stdlib.h>
#include<pthread.h>
#include <stdbool.h>


int Dissemination(int num_threads); // implementation

void* dissemination_barrier(void *Arguments);

struct dissemination_args {
    bool test;
};
