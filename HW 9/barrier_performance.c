#include "barrier_performance.h"



int main(){
    FILE *output;
    clock_t start, end;

    output = fopen("barrier_performance.csv", "w"); // file to write to
    fprintf(output, "Barrier,Size,Trial,Time\n");

    int sizes[10] = {1,2,4,8,16,32,64,128, 256, 512};


    for (int i = 0; i < 100; i++) //itterate trials
    {
        for (size_t j = 0; j < 10; i++) // itterate sizes
        {
            start = clock();
            Centralized(sizes[i]);
            end = clock();

            fprintf(output, "centralized,%i,%i,%f\n", sizes[j], i, (end-start)/CLOCKS_PER_SEC);
        }
    }

    for (int i = 0; i < 100; i++) //itterate trials
    {
        for (size_t j = 0; j < 10; i++) // itterate sizes
        {
            start = clock();
            Dissemination(sizes[i]);
            end = clock();

            fprintf(output, "dissemination,%i,%i,%f\n", sizes[j], i, (end-start)/CLOCKS_PER_SEC);
        }
    }

    fclose(output);
    
}