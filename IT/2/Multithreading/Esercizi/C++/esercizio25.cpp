/*
file esercizio25.cpp
compilare con: g++ -std=c++11 esercizio25.cpp -lpthread -I.
oppure (c++20):
g++ -std=c++20 esercizio25.cpp -lpthread
*/

#include <random>
#include <thread>
#include <chrono>
#include <deque>
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
using std::chrono::duration;
using std::chrono::seconds;
using std::ref;
using std::deque;

void philosopher(const char* name, deque<binary_semaphore>& forks, int rIndex, int lIndex) {
	thread_local default_random_engine gen(random_device{}());

	while (true) {
		if (forks[rIndex].try_acquire()) {
			if (forks[lIndex].try_acquire()) {
				printf("%s prende le forchette %d e %d.\n", name, rIndex, lIndex);
				printf("%s sta mangiando.\n", name);
				// ogni filosofo impiega tra 4 e 8 secondi per mangiare
				uniform_int_distribution<int> dist(4, 8);
				seconds duration(dist(gen));
				std::this_thread::sleep_for(duration);

				printf("%s posa le forchette %d e %d.\n", name, rIndex, lIndex);
				forks[lIndex].release();
			}

			forks[rIndex].release();
		}

		// ogni filosofo pensa per 3/5 secondi
		uniform_int_distribution<int> dist(3, 5);
		seconds duration(dist(gen));
		std::this_thread::sleep_for(duration);
		printf("%s sta pensando...\n", name);
	}
}

int main()
{
	const int N_PHILOSOPHERS = 5;
	const char* names[] = {"Platone", "Pitagora", "Kant", "Leibniz", "Marx"};

	deque<binary_semaphore> forks;
	for (int i = 0; i < 5; i++) forks.emplace_back(1);

	thread philosophers[N_PHILOSOPHERS];

	for (int i = 0; i < N_PHILOSOPHERS; i++) {
		philosophers[i] = thread(philosopher, names[i], ref(forks), i, (i+1) % N_PHILOSOPHERS);
	}

	for (auto& thread : philosophers) {
		thread.join();
	}
}

