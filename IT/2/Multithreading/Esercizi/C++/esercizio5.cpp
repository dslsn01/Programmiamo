/*
file esercizio5.cpp
compilare con: g++ -std=c++11 esercizio5.cpp -lpthread
*/

#include <iostream>
#include <random>
#include <future>

using std::cin;
using std::cout;
using std::endl;
using std::random_device;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::async;
using std::future;

void func() {
	printf("Ciao, mondo!\n");
}

int main()
{
	default_random_engine gen(random_device{}());
	uniform_int_distribution<int> dist(2, 10);

	int nThreads = dist(gen);

	cout << "Verrà creato un pool di " << nThreads << " thread." << endl;

	for (int i = 0; i < nThreads; i++) {
		async(std::launch::async, func);
	}
}

