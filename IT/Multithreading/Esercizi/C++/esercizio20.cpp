/*
file esercizio20.cpp
compilare con: g++ -std=c++11 esercizio20.cpp -lpthread -I.
oppure (c++20):
g++ -std=c++20 esercizio20.cpp -lpthread
*/

#include <random>
#include <thread>
#if __cplusplus > 201703L
#include <semaphore>
using std::binary_semaphore;
#else
#include "semaphore.h"
using binary_semaphore = counting_semaphore<1>;
#endif

using std::random_device;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::thread;
using std::chrono::high_resolution_clock;
using std::chrono::duration;
using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::milliseconds;
using std::ref;

class Barrier {
	private:
		int n;
		int count;
		binary_semaphore mutex;
		binary_semaphore barrier;

	public:
		Barrier(int n);
		~Barrier() = default;
		void await();
};

Barrier::Barrier(int n) : n(n), count(0), mutex(1), barrier(0) {}

void Barrier::await() {
	mutex.acquire();
	count++;
	mutex.release();

	if (this->count == this->n) {
		barrier.release();
	}

	barrier.acquire();
	barrier.release();
}

void func(Barrier& barrier, int i) {
	thread_local default_random_engine gen(random_device{}());
	uniform_int_distribution<int> dist(3, 8);
	seconds duration(dist(gen));
	std::this_thread::sleep_for(duration);
	barrier.await();

	// stampa l'istante in millisecondi 

	auto startT = high_resolution_clock::now().time_since_epoch();
	auto millis = duration_cast<milliseconds>(startT).count();

	printf("%ld thread %d\n", millis, i);
}

int main()
{
	const int N_THREADS = 3;
	Barrier barrier(N_THREADS);

	thread threads[N_THREADS];

	for (int i = 0; i < N_THREADS; i++) {
		threads[i] = thread(func, ref(barrier), i);
	}

	for (auto& t : threads) {
		t.join();
	}
}

