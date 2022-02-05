#include "update_locations.hh"

// header file includes function defs as weel as `vec_t` alias

vec_t* generate_random_list(int size, int bound){
	vec_t* list = (vec_t*)malloc(size*sizeof(vec_t));
	for(int i =0; i<size; i++){
		list[i] = (rand()%(2*bound))-bound;//
	}
	return list;
}

void update_coords(vec_t* xs, vec_t* ys, vec_t* zs, vec_t* vx, vec_t* vy, vec_t* vz, int size){
	for(int j = 0; j<size; j++){
		xs[j] = xs[j] + vx[j];
		ys[j] = ys[j] + vy[j];
		zs[j] = zs[j] + vz[j];
	}
}

vec_t sum(vec_t* arr, int size){
	vec_t total = 0.0;
	for(int k=0; k<size; k++){
		total+= arr[k];
	}
	return total;
}

double time_exe(vec_t* xs, vec_t* ys, vec_t* zs, vec_t* vx, vec_t* vy, vec_t* vz, int size){
	clock_t start, end;
	
	start = clock(); // Start timer
	update_coords(xs, ys, zs, vx, vy, vz, size);
	end = clock(); // End timer
	
	return (end-start)*CLOCKS_PER_SEC*pow(10, -5); // returns microseconds
}



int main(int argc, char* argv[]){
	
	if(argc!=3){
		// asserts and stops if error
		printf("Required arguments: vector_length(N) and iterations_num(M)\n");
		return -1;
	}

	int size = atoi(argv[1]); // gets size of array for command
	int iters = atoi(argv[2]); // gets 
	vec_t chksum = 0;
	srand(size);
	double time = 0.;

	vec_t* xs = generate_random_list(size, 1000);
	vec_t* ys = generate_random_list(size, 1000);
	vec_t* zs = generate_random_list(size, 1000);
	vec_t* vx = generate_random_list(size, 1);
	vec_t* vy = generate_random_list(size, 1);
	vec_t* vz = generate_random_list(size, 1);

	for(int l= 0;l<iters;l++){
		time += time_exe(xs, ys, zs, vx, vy, vz, size);
	}


	chksum = sum(xs, size) + sum(ys, size) + sum(zs, size);

	printf("Mean time per coordinate: %f us\n", time / (size * iters)); 
	printf("Final checksum is: %f\n", chksum);
	
	free(xs);
	free(ys);
	free(zs);
	free(vx);
	free(vy);
	free(vz);

	return 0;
}
