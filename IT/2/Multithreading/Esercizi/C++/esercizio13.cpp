/*
file esercizio13.cpp
compilare con: g++ -std=c++11 esercizio13.cpp -lpthread
*/

#include <iostream>
#include <random>
#include <chrono>
#include <thread>
#include <mutex>

using std::cout;
using std::endl;
using std::string;
using std::random_device;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::chrono::seconds;
using std::thread;
using std::mutex;
using std::this_thread::sleep_for;

void func(mutex& lock, int i)
{
	//lock_guard<std::mutex> lock(mutex);
	lock.lock();

	printf("Il thread %d entra nella funzione target.\n", i);
	sleep_for(seconds(5));
	printf("Il thread %d esce dalla funzione target.\n", i);

	lock.unlock();
}

int main()
{
	default_random_engine gen(random_device{}());
	uniform_int_distribution<int> dist(2, 10);

	int nThreads = dist(gen);

	cout << "Verranno creati " << nThreads << " thread." << endl;

	mutex lock;
	thread threads[nThreads];

	for (int i = 0; i < nThreads; i++) {
		threads[i] = thread(func, ref(lock), i);
	}

	for (auto &thread : threads) {
		thread.join();
	}
}

