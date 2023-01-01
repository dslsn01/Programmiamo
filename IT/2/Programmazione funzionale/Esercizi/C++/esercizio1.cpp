/*
file esercizio1.cpp
compilare con: g++ -std=c++11 esercizio1.cpp
*/

#include <iostream>
#include <random>

using std::cout;
using std::endl;
using std::random_device;
using std::default_random_engine;
using std::uniform_int_distribution;

int f(int a, int b, int c) {
	if (a > b) {
		return a > c ? a : c;
	}
	else {
		return b > c ? b : c;
	}
}

int main() {
	default_random_engine gen(random_device{}());
	uniform_int_distribution<int> dist(1, 10);
	int a = dist(gen);
	int b = dist(gen);
	int c = dist(gen);

	cout << "a=" << a << ", b=" << b << ", c=" << c << endl;
	cout << "Numero maggiore: " << f(a, b, c) << endl;
}

