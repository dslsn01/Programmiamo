/*
file esercizio26.cpp
compilare con: g++ -std=c++11 esercizio26.cpp -lpthread -I.
oppure (c++20):
g++ -std=c++20 esercizio25.cpp -lpthread
*/

#include <random>
#include <string>
#include <deque>
#include <thread>
#include <mutex>
#if __cplusplus > 201703L
#include <semaphore>
using std::counting_semaphore;
#else
#include "semaphore.h"
#endif
using semaphore = counting_semaphore<25>;

using std::random_device;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::thread;
using std::mutex;
using std::chrono::duration;
using std::chrono::seconds;
using std::ref;
using std::string;
using std::deque;

void producer(mutex& lock, semaphore& full, semaphore& empty, deque<string>& items, int i) {
	thread_local default_random_engine gen(random_device{}());

	while (true) {
		string item = "pacco regalo";
		empty.acquire();
		lock.lock();
		items.push_front(item);
		lock.unlock();
		printf("thread %d prepara un pacco regalo (%d disponibili).\n", i, items.size());
		full.release();

		uniform_int_distribution<int> dist(1, 25);
		seconds duration(dist(gen));
		std::this_thread::sleep_for(duration);
	}
}

void consumer(mutex& lock, semaphore& full, semaphore& empty, deque<string>& items, int i) {
	thread_local default_random_engine gen(random_device{}());

	while (true) {
		full.acquire();
		lock.lock();
		string item = items.front();
		items.pop_front();
		lock.unlock();
		printf("thread %d acquista un %s (%d rimanenti).\n", i, item.c_str(), items.size());
		empty.release();

		uniform_int_distribution<int> dist(1, 25);
		seconds duration(dist(gen));
		std::this_thread::sleep_for(duration);
	}
}

int main()
{
	const int BUFFER_SIZE = 25;
	mutex lock;
	semaphore full(0);
	semaphore empty(BUFFER_SIZE);
	deque<string> items;

	thread tproducer(producer, ref(lock), ref(full), ref(empty), ref(items), 0);
	thread tconsumer(consumer, ref(lock), ref(full), ref(empty), ref(items), 1);

	tproducer.join();
	tconsumer.join();
}

