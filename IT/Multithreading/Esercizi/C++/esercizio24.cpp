/*
file esercizio24.cpp
compilare con: g++ -std=c++11 esercizio24.cpp -lpthread
*/

#include <random>
#include <thread>
#include <mutex>
#include <chrono>
#include <array>

using std::random_device;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::thread;
using std::recursive_mutex;
using std::chrono::seconds;
using std::array;

void philosopher(const char* name, array<std::recursive_mutex, 5>& forks, int rIndex, int lIndex) {
	thread_local default_random_engine gen(random_device{}());

	while (true) {
		if (forks[rIndex].try_lock()) {
			if (forks[lIndex].try_lock()) {
				printf("%s prende le forchette %d e %d.\n", name, rIndex, lIndex);
				printf("%s sta mangiando.\n", name);
				// ogni filosofo impiega tra 4 e 8 secondi per mangiare
				uniform_int_distribution<int> dist(4, 8);
				seconds duration(dist(gen));
				std::this_thread::sleep_for(duration);

				printf("%s posa le forchette %d e %d.\n", name, rIndex, lIndex);
				forks[lIndex].unlock();
			}

			forks[rIndex].unlock();
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

	array<recursive_mutex, 5> forks;
	thread philosophers[N_PHILOSOPHERS];

	for (int i = 0; i < N_PHILOSOPHERS; i++) {
		philosophers[i] = thread(philosopher, names[i], ref(forks), i, (i+1) % N_PHILOSOPHERS);
	}

	for (auto& thread : philosophers) {
		thread.join();
	}
}

