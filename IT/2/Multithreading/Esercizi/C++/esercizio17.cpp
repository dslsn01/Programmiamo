/*
file esercizio17.cpp
compilare con: g++ -std=c++11 esercizio17.cpp -lpthread -I.
oppure (c++20):
g++ -std=c++20 esercizio17.cpp -lpthread
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
using semaphore = counting_semaphore<3>;

using std::random_device;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::thread;
using std::this_thread::sleep_for;
using std::chrono::duration;
using std::chrono::seconds;
using std::ref;
using std::list;

void car(semaphore& sem, int i) {
	thread_local default_random_engine gen(random_device{}());

	uniform_int_distribution<int> dist1(45, 90);
	int speed = dist1(gen);
	printf("L'auto thread %d viaggia a %d km/h...\n", i, speed);

	uniform_int_distribution<int> dist2(3, 5);
	seconds duration(dist2(gen));
	sleep_for(duration);

	sem.acquire();
	printf("Il thread %d attraversa l'incrocio.\n", i);
	sem.release();
}

int main()
{
	semaphore sem(1);
	list<thread> cars;

	default_random_engine gen(random_device{}());
	int i = 0;

	for (int i = 0; i < 25; i++) {
		cars.push_back(thread(car, ref(sem), i));
		uniform_int_distribution<int> dist(0, 1);
		seconds duration(dist(gen));
		sleep_for(duration);
		i++;
	}

	for (auto& car : cars) {
		car.join();
	}
}

