#include <iostream>

#include "Random.h"
#include "Fibonacci.h"

using namespace std;

int main() {
	int rng = rand_int(10, 25);
	cout << "Number: " << rng << endl;
	cout << "Slow " << fib(rng) << endl;
	cout <<  "Fast " << fibFaster(rng) << endl;
	return 0;
}