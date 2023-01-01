/*
file esercizio15.cpp
compilare con: g++ -std=c++11 esercizio15.cpp -lpthread
*/

#include <iostream>
#include <thread>
#include <condition_variable>

using std::ref;
using std::thread;
using std::mutex;
using std::unique_lock;
using std::condition_variable;

void add(int& value, mutex& _mutex, condition_variable& condition, int i)
{
	unique_lock<mutex> lock(_mutex);

	while (value > 0) condition.wait(lock);

	printf("thread %d - variabile (prima dell'incremento): %d\n", i, value/*.load()*/);

	value++;

	printf("thread %d - variabile (dopo l'incremento): %d\n", i, value/*.load()*/);

	condition.notify_one();
}

void subtr(int& value, mutex& _mutex, condition_variable& condition, int i)
{
	unique_lock<mutex> lock(_mutex);

	if (value == 0) condition.wait(lock);

	printf("thread %d - variabile (prima del decremento): %d\n", i, value);

	value--;

	printf("thread %d - variabile (dopo il decremento): %d\n", i, value);

	condition.notify_one();
}

int main()
{
	int value = 0;
	mutex lock;
	condition_variable condition;

	thread t1(add, ref(value), ref(lock), ref(condition), 1);
	thread t2(subtr, ref(value), ref(lock), ref(condition), 2);

	t1.join();
	t2.join();
}

