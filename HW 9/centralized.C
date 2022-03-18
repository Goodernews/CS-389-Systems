#include "centralized.hh"

int counter = 1;
bool sense = false;
void barrier(P){
	bool local_sense = ! sense;
	if (fetch_and_increment(&counter) == P) {
		counter = 1;
		sense = local_sense;
	} 
	
	else{
		while (sense != local_sense){
		       	/* spin */ }
	}
}
