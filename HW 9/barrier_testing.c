#include "barrier_testing.h"




int main(int argc, char argv[]){
	test_centralized();
	test_dissemination();
	test_mcs();

	return 0;
}

void test_centralized(){
	// The code is itself a test, if it runs endlessly 
	// then it is broken
	Centralized(1); 
	Centralized(5); 
	Centralized(100);
}

void test_dissemination(){
	Dissemination(1);
	Dissemination(10);
}

void test_MCS();

