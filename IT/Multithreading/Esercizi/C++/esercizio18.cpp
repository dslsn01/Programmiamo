/*
file esercizio18.cpp
compilare con: g++ -std=c++11 esercizio18.cpp -lpthread -I.
oppure (c++20):
g++ -std=c++20 esercizio18.cpp -lpthread
*/

#include <random>
#include <thread>
#include <list>
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

class VendingMachine {
	private:
		static const char* drinks[];
		binary_semaphore sem;

	public:
		VendingMachine();
		~VendingMachine() = default;
		void select(int);
};

VendingMachine::VendingMachine() : sem(1) {}

const char* VendingMachine::drinks[] = { "acqua", "Coca Cola", "Fanta", "Sprite", "the freddo" };

void VendingMachine::select(int i) {
	thread_local default_random_engine gen(random_device{}());

	// attende tra zero e 10 secondi per entrare nell'area di ristoro
	uniform_int_distribution<int> dist(0, 10);
	seconds duration(dist(gen));
	std::this_thread::sleep_for(duration);
	printf("thread %d entra nella zona pausa.\n", i);

	this->sem.acquire();

	uniform_int_distribution<int> dist2(5, 10);
	std::this_thread::sleep_for(seconds(dist2(gen)));
	uniform_int_distribution<int> dist3(0, 4);
	printf("thread %d ha selezionato %s.\n", i, drinks[dist3(gen)]);

	this->sem.release();
}

void func(int i, VendingMachine& dMachine) {
	dMachine.select(i);
}

int main()
{
	VendingMachine dMachine;
	thread consumers[10];

	for (int i = 0; i < 10; i++) {
		consumers[i] = thread(func, i, ref(dMachine));
	}

	for (auto& t : consumers) {
		t.join();
	}
}

