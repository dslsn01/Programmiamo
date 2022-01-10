/*
file esercizio18.cpp
compilare con: g++ -std=c++11 esercizio18.cpp
*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
#include <random>

using std::cout;
using std::endl;
using std::setprecision;
using std::random_device;
using std::default_random_engine;
using std::uniform_int_distribution;

double recp(int n) {
	if (n == 0) return NAN;
	return (double) 1/n;
}

int main() 
{
	default_random_engine gen(random_device{}());

	for (int i = 0; i < 5; i++) {
		uniform_int_distribution<int> dist(2, 15);
		int r = dist(gen);
		double rp = recp(r);
		cout << "Il reciproco di " << setprecision(3) << r <<" è " << rp << "." << endl;
	}
}

