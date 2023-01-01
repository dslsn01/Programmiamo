/*
file copyshop.cpp
compilare con: 
g++ -std=c++11 copyshop.cpp -lpthread -I.
oppure (c++20):
g++ -std=c++20 copyshop.cpp -lpthread
*/

#include <random>
#include <chrono>
#include <thread>
#include <cstdio>
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
using std::chrono::seconds;
using std::this_thread::sleep_for;
using std::thread;
using std::ref;

void printingJob(binary_semaphore& printer, const char* doc, int i) {
	thread_local default_random_engine gen(random_device{}());

	// documento inviato in un intervallo di tempo tra 1 e 25 secondi
	uniform_int_distribution<int> dist1(1, 25);
	seconds duration(dist1(gen));
	sleep_for(duration);

	printf("Il thread %d invia il documento \"%s\" alla stampante.\n", i, doc);

	// acquisisce il semaforo-stampante
	printer.acquire();

	uniform_int_distribution<int> dist2(5, 10);
	sleep_for(seconds(dist2(gen)));
	printf("Stampato il documento \"%s\" inviato dal thread %d.\n", doc, i);

	// libera il semaforo-stampante
	printer.release();
}

int main() {
	// il semaforo rappresenta una stampante condivisa
	binary_semaphore printer(1);

	const char* documents[] = { "Modulo di iscrizione", "Appunti d'esame", "Tesi laurea triennale", "Tesi laurea specialistica", "Tesi dottorato" };

	thread students[10];
	default_random_engine gen(random_device{}());

	for (int i = 0; i < 10; i++) {
		uniform_int_distribution<int> dist(0, 4);
		int t = dist(gen);

		students[i] = thread(printingJob, ref(printer), documents[t], i);
	}

	for (auto& student : students) {
		student.join();
	}
}

