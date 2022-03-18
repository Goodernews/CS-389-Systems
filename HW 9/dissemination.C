
#include "dissemination.hh"

const int rounds = log(P);
bool flags[P][2][rounds]; // allocated in local storage per thread
local bool sense = false;
local int parity = 0;

void barrier() {
	for (round = 0 to rounds – 1) {
		partner = (tid + 2^round) mod P;
		flags[partner][parity][round] = !sense;
		while (flags[tid][parity][round] == sense)
			{ /* spin */ }
	}
	if (parity == 1) {
		sense = !sense;
	}
	parity = 1 – parity;
}
