/*
file esercizio14.cpp
compilare con: g++ -std=c++11 esercizio14.cpp -lpthread
*/

#include <iostream>
#include <thread>
#include <mutex>
// #include <atomic>

using std::thread;
// using std::atomic;
using std::mutex;
using std::lock_guard;
using std::ref;

void func(/*atomic<int>*/int& value, mutex& _mutex, int i)
{
	lock_guard<mutex> lock(_mutex);

	printf("thread %d - variabile (prima dell'incremento): %d\n", i, value/*.load()*/);

	// value.fetch_add(1);
	value++;

	printf("thread %d - variabile (dopo l'incremento): %d\n", i, value/*.load()*/);
}

int main()
{
	int value = 0;
	mutex lock;
	// atomic<int> value(0);

	thread t1(func, ref(value), ref(lock), 1);
	thread t2(func, ref(value), ref(lock), 2);

	t1.join();
	t2.join();
}

