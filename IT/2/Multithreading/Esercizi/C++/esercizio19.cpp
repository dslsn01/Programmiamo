/*
file esercizio19.cpp
compilare con: g++ -std=c++11 esercizio19.cpp -lpthread -I.
oppure (c++20):
g++ -std=c++20 esercizio19.cpp -lpthread
*/

#include <random>
#include <thread>
#include <list>
#if __cplusplus > 201703L
#include <semaphore>
using std::counting_semaphore;
#else
#include "semaphore.h"
#endif
using semaphore = counting_semaphore<4>;

using std::random_device;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::thread;
using std::chrono::duration;
using std::chrono::seconds;
using std::ref;

class PollingStation {
	private:
		semaphore cabin;

	public:
		PollingStation();
		~PollingStation() = default;
		void vote(int);
};

PollingStation::PollingStation() : cabin(4) {}

void PollingStation::vote(int i) {
	thread_local default_random_engine gen(random_device{}());

	// attende tra zero e 10 secondi per entrare nel seggio elettorale
	uniform_int_distribution<int> dist(0, 10);
	seconds duration(dist(gen));
	std::this_thread::sleep_for(duration);
	printf("thread %d entra nel seggio elettorale.\n", i);

	this->cabin.acquire();

	uniform_int_distribution<int> dist2(5, 10);
	std::this_thread::sleep_for(seconds(dist2(gen)));
	printf("thread %d ha votato.\n", i);

	this->cabin.release();
}

void func(int i, PollingStation& pStation) {
	pStation.vote(i);
}

int main()
{
	PollingStation pStation;
	thread voters[25];

	for (int i = 0; i < 25; i++) {
		voters[i] = thread(func, i, ref(pStation));
	}

	for (auto& t : voters) {
		t.join();
	}
}

