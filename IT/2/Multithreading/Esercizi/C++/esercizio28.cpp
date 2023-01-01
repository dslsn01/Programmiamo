/*
file esercizio28.cpp
compilare con: g++ -std=c++11 esercizio28.cpp -lpthread -I.
oppure (c++20):
g++ -std=c++20 esercizio28.cpp -lpthread
*/

#include <random>
#include <thread>
#include <mutex>
#if __cplusplus > 201703L
#include <semaphore>
using std::counting_semaphore;
#else
#include "semaphore.h"
#endif
using semaphore = counting_semaphore<1>;

using std::random_device;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::thread;
using std::mutex;
using std::chrono::duration;
using std::chrono::seconds;
using std::ref;

void barber(semaphore& barberReady, semaphore& accessWRSeats, semaphore& customerReady, int& numberOfFreeWRSeats, int* customers, int i) {
	thread_local default_random_engine gen(random_device{}());

	while (true) {
		customerReady.acquire();
		accessWRSeats.acquire();
		int pc = customers[numberOfFreeWRSeats];
		numberOfFreeWRSeats += 1;
		barberReady.release();
		accessWRSeats.release();

		printf("Il barbiere thread %d sta tagliando i capelli al cliente thread %d.\n", i, pc);
		uniform_int_distribution<int> dist(10, 25);
		int pause = dist(gen);
		seconds duration(pause);
		std::this_thread::sleep_for(duration);

		printf("thread %d ha impiegato %d minuti per tagliare i capelli a thread %d. Avanti un altro!\n", i, pause, pc);
	}
}

void customer(semaphore& barberReady, semaphore& accessWRSeats, semaphore& customerReady, int& numberOfFreeWRSeats, int* customers, int i) {
	thread_local default_random_engine gen(random_device{}());

	printf("Il cliente thread %d entra nel negozio.\n", i);
	accessWRSeats.acquire();

	if (numberOfFreeWRSeats > 0) {
		numberOfFreeWRSeats -= 1;
		customers[numberOfFreeWRSeats] = i;
		printf("thread %d si siede e aspetta di farsi tagliare i capelli...\n", i);
		customerReady.release();
		accessWRSeats.release();
		barberReady.acquire();
	}
	else {
		printf("Il cliente thread %d non ha trovato posto per sedersi ed esce dal negozio...\n", i);
		customerReady.release();
	}

	uniform_int_distribution<int> dist(1, 25);
	seconds duration(dist(gen));
	std::this_thread::sleep_for(duration);
}

int main()
{
	semaphore barberReady(0);
	semaphore accessWRSeats(1);
	semaphore customerReady(0);
	int numberOfFreeWRSeats = 5;

	int customers[5] = {0, 0, 0, 0, 0};
	int i = 1;

	thread tbarber(barber, ref(barberReady), ref(accessWRSeats), ref(customerReady), ref(numberOfFreeWRSeats), customers, i);

	thread processes[25];

	while (true) {
		i++;
		processes[i] = thread(customer, ref(barberReady), ref(accessWRSeats), ref(customerReady), ref(numberOfFreeWRSeats), customers, i);
		thread_local default_random_engine gen(random_device{}());
		uniform_int_distribution<int> dist(5, 30);
		seconds duration(dist(gen));
		std::this_thread::sleep_for(duration);
	}

	tbarber.join();

	for (auto& c : processes) {
		c.join();
	}
}

