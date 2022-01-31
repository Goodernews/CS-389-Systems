#include<stdio.h>
#include <stdlib.h>



int main(int argc,char* argv[]){

	int i; //for itterating the for loop
	int arr_size = atoi(argv[1]); // gets the first user input and makes it the array size
	int seed = atoi(argv[2]); // gets second val and makes it the seed value
	int rand_nums[arr_size]; // creates int array of `arr_size`
	int sum = 0; 
	srand(seed); // sets seed	

	for(i=0; i<arr_size; i++){
		rand_nums[i] = rand();
	}

	for(i=0; i < arr_size; i++){
		sum += rand_nums[i];
	}

	printf("The mean value of the array is: %.3f \n", (double)sum/arr_size);

	return 0;
}
