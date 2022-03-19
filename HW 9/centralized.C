#include "centralized.hh"

void* centralized_barrier(void *Arguments){
	struct args *arguments = (struct args*)Arguments;
	bool local_sense = ! arguments->Sense;
	if (arguments->Counter.fetch_add(1) == arguments->Nthreads) {
		arguments->Counter = 0;
		arguments->Sense = local_sense;
	} 
	
	else{
		while (arguments->Sense != local_sense){
		       	/* spin */ }
	}
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
