#include "centralized.h"

void* centralized_barrier(void *Arguments){
	struct centralized_args *arguments = (struct centralized_args*)Arguments;
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
	struct centralized_args *pass_through = (struct centralized_args *)malloc(sizeof(struct centralized_args));
	
	pass_through->Counter = 0;
	pass_through->Sense = false;
	pass_through->Nthreads = num_threads;
	
	pthread_t *tid;

    tid = malloc(num_threads * sizeof *tid); // makes 

	for(int i = 0; i<num_threads; i++){
		pthread_create(&tid[i], NULL, &centralized_barrier, pass_through); //initializes
	}

	for(int i = 0;i<num_threads; i++) {
        pthread_join(tid[i], NULL); // runs
    }

    free(tid); // frees allocated threads
	return 0;
}

int main(){
	Centralized(10);
	return 0;
}
