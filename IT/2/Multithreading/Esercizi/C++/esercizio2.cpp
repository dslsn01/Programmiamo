/*
file esercizio2.cpp
compilare con: g++ -std=c++11 esercizio2.cpp -lpthread
*/

#include <iostream>
#include <random>
#include <thread>

using std::cin;
using std::cout;
using std::endl;
using std::random_device;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::thread;

void func(int n) {
	printf("thread %d\n", n);
}

int main()
{
	default_random_engine gen(random_device{}());
	uniform_int_distribution<int> dist(2, 10);

	int nThreads = dist(gen);

	cout << "Verranno creati " << nThreads << " thread." << endl;

	thread threads[nThreads];

	for (int i = 0; i < nThreads; i++) {
		threads[i] = thread(func, i);
	}

	for (auto &thread : threads) {
		thread.join();
	}
}

