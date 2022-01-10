/*
file esercizio12.cpp
compilare con: g++ -std=c++11 esercizio12.cpp -lpthread
*/

#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

using std::chrono::seconds;
using std::thread;
using std::mutex;
using std::this_thread::sleep_for;
//using std::unique_lock;
//using std::lock_guard;

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
	mutex lock;
	thread threads[3];

	for (int i = 0; i < 3; i++) {
		threads[i] = thread(func, ref(lock), i);
	}

	for (auto &thread : threads) {
		thread.join();
	}
}

