#include "Benchmark.h"


int main(int argc, char* argv[]){
    /*
    function takes three components:
    1. iterations
    2. Exponent by
    3. Max value
    */
    if(argc!=4){
        printf("Please provide three arugments: <Iterations>, <Power by>, <Max Value>");
    }

    FILE *output;
    int trials = atoi(argv[1]); // How many trials for each number of bytes
    int pow_by = atoi(argv[2]); // Denomination of bytes (ex. 10 would be 1, 10, 100) 
    int max_val = atoi(argv[3]); // Max number of byes
    int iters = log(max_val)/log(pow_by); // number of iterations (num new arrays)
    vec_t* size_array = (vec_t*)malloc(iters*sizeof(vec_t)); // holds array of num bytes
    int size; //stores value of 
    
    
    // Return a csv of two columns
    // Size | Time (NS)
    output = fopen("Output.csv", "w"); // file to write to
    fprintf(output, "Size (Bytes),Time (NS),Trial\n");

    

    size_array[0] = max_val; // max value

    for(int i=1; i<iters; i++){
        size_array[i] = size_array[i-1]/pow_by; // Take previous value div by 
    }


    for(int j=0; j<iters; j++){
        if(size_array[j]*8 < sizeof(vec_t)){ // if smaller than 
            continue;
        }

        size = floor(size_array[j]*8 /sizeof(vec_t)); // stores how many elements to make up a given number of bytes
        vec_t* rand_list = generate_random_list(size);
    // allocate a list of size bytes
    
        for(int k=0; k<trials; k++){
            fprintf(output, "%i,%f,%i\n", size_array[j], time_exe(size_array[j], rand_list), k); //write out results
        }

        free(rand_list); // release memory after iteration

    }

    fclose(output);
    printf("Written to file\n");

    return 0;

}


double time_exe(int size, vec_t* rand_list){
    	clock_t start, end; // start and end time
    	vec_t _0, _1, _2, _3, _4, _5, _6, _7, _8, _9; // holds random accessed variable
    	int access_index_0 = rand()%size; // picks an index
    	int access_index_1 = rand()%size;
    	int access_index_2 = rand()%size;
    	int access_index_3 = rand()%size;
	int access_index_4 = rand()%size;
 	int access_index_5 = rand()%size;
 	int access_index_6 = rand()%size;
  	int access_index_7 = rand()%size;
  	int access_index_8 = rand()%size;
 	int access_index_9 = rand()%size;
 

	start = clock();
    	_0 = rand_list[access_index_0];//execute here
    	_1 = rand_list[access_index_1];
    	_2 = rand_list[access_index_2];
    	_3 = rand_list[access_index_3];
	_4 = rand_list[access_index_4];//execute here
    	_5 = rand_list[access_index_5];
    	_6 = rand_list[access_index_6];
    	_7 = rand_list[access_index_7];
	_8 = rand_list[access_index_8];//execute here
    	_9 = rand_list[access_index_9];
	end = clock();

    srand(((_0+_1)%(_2+_3))+((_4+_5)%(_6+_7))+(_8%_9)); // So the compiler doesn't become smart and not execute the line above, this is included

    return ((double)(end-start))/(CLOCKS_PER_SEC)*1e8; // returns nano sec time 1e9 /10
}

vec_t* generate_random_list(int size){
    vec_t* list = (vec_t*)malloc(size*sizeof(vec_t));
	for(int i =0; i<size; i++){
		list[i] = rand()% max_num;//
	}
	return list;
}

