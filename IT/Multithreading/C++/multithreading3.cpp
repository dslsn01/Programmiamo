/*
file multithreading3.cpp
compilare con: g++ -std=c++11 multithreading3.cpp -lpthread
*/

#include <cstdlib>
#include <random>
#include <chrono>
#include <thread>

using std::random_device;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::chrono::seconds;
using std::this_thread::sleep_for;
using std::thread;

void selectFromDb(const char* tname)
{
	printf("%s - selezione database\n", tname);

	thread_local default_random_engine gen(random_device{}());

	for (int i = 0; i < 3; i++) {
		printf("%s - elaborazione dati...\n", tname);
		// pausa da 1 a 3 secondi
		uniform_int_distribution<int> dist(1, 3);
		seconds duration(dist(gen));
		sleep_for(duration);
	}
}

/* l'invocazione a this_thread::sleep_for() lascia il processore al thread che esegue la select */

void mainFunc(const char* tname)
{
	thread_local default_random_engine gen(random_device{}());

	for (int i = 0; i < 3; i++) {
		printf("%s - ciclo principale\n", tname);
		// pausa da 1 a 3 secondi
		uniform_int_distribution<int> dist(1, 3);
		seconds duration(dist(gen));
		sleep_for(duration);
	}
}

int main() 
{
	/* crea due nuovi thread */

	thread t1(mainFunc, "MAIN");
	thread t2(selectFromDb, "BACKGROUND");

	t1.join();
	t2.join();

	printf("Dati dal database pronti all'uso!\n");
}

