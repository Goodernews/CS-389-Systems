#include "centralized.h"

void* centralized_barrier(void *Arguments){
	struct args *arguments = (struct args*)Arguments;
	bool local_sense = ! arguments->Sense;
	if (atomic_fetch_add_explicit(&arguments->Counter, 1, memory_order_relaxed) == arguments->Nthreads) {
		arguments->Counter = 0;
		arguments->Sense = local_sense;
	} 
	
	else{
		while (arguments->Sense != local_sense){
		       	/* spin */ }
	}

	return 0;

}


int Centralized(int num_threads){
	struct args *pass_through = (struct args *)malloc(sizeof(struct args));
	
	pass_through->Counter = 0;
	pass_through->Sense = false;
	pass_through->Nthreads = num_threads;
	
	pthread_t threads;


	for(int i = 0; i<num_threads; i++){
		pthread_create(&threads, NULL, centralized_barrier, pass_through);
	}

	return 0;
}

int main(){
	return 0;
}
