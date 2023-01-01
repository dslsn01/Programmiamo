/*
file esercizio27.cpp
compilare con: g++ -std=c++11 esercizio27.cpp -lpthread -I.
oppure (c++20):
g++ -std=c++20 esercizio27.cpp -lpthread
*/

#include <thread>
#include <mutex>
#if __cplusplus > 201703L
#include <semaphore>
using std::counting_semaphore;
#else
#include "semaphore.h"
#endif
using semaphore = counting_semaphore<1>;

using std::thread;
using std::mutex;
using std::ref;

void writer(semaphore& serviceQueue, semaphore& resourceAccess, int i) {
	serviceQueue.acquire();
	resourceAccess.acquire();
	serviceQueue.release();

	printf("thread %d scrive.\n", i);

	resourceAccess.release();
}

void reader(semaphore& serviceQueue, int& readCount, semaphore& readCountAccess, semaphore& resourceAccess, int i) {
	serviceQueue.acquire();
	readCountAccess.acquire();

	if (readCount == 0) {
		resourceAccess.acquire();
	}

	readCount++;

	serviceQueue.release();
	readCountAccess.release();

	printf("thread %d legge.\n", i);

	readCountAccess.acquire();
	readCount--;

	if (readCount == 0) {
		resourceAccess.release();
	}

	readCountAccess.release();
}

int main()
{
	int readCount = 0;
	semaphore resourceAccess(1);
	semaphore readCountAccess(1);
	semaphore serviceQueue(1);

	const int N_WRITERS = 5;
	const int N_READERS = 10;

	thread writers[N_WRITERS];

	for (int i = 0; i < N_WRITERS; i++) {
		writers[i] = thread(writer, ref(serviceQueue), ref(resourceAccess), i);
	}

	thread readers[N_READERS];

	for (int i = 0; i < N_READERS; i++) {
		readers[i] = thread(reader, ref(serviceQueue), ref(readCount), ref(readCountAccess), ref(resourceAccess), i);
	}

	for (auto& w : writers) {
		w.join();
	}

	for (auto& r : readers) {
		r.join();
	}
}

