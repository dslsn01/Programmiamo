/*
file wildWildWest.cpp 
compilare con: g++ -std=c++11 wildWildWest.cpp -lpthread
*/

#include <string>
#include <cstdlib>
#include <random>
#include <chrono>
#include <thread>
#include <mutex>

using std::string;
using std::ref;
using std::random_device;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::chrono::seconds;
using std::this_thread::sleep_for;
using std::thread;
using std::mutex;

void tieCows(mutex& lock, const char* tname) {
	static thread_local default_random_engine gen(random_device{}());

	lock.lock();

	for (int i = 0; i < 3; i++) {
		printf("Il cowboy %s sta chiudendo le sue mucche nella stalla...\n", tname);

		uniform_int_distribution<int> dist(1, 3);
		seconds duration(dist(gen));
		sleep_for(duration);
	}

	lock.unlock();
}

int main()
{
	/* i due oggetti CowBoy condividono la stessa stalla */

	mutex lock;

	/* istanzia e avvia due thread che eseguono la funzione tieCows() */

	thread wyatt(tieCows, ref(lock), "Wyatt Earp");
	thread buffalo(tieCows, ref(lock), "Buffalo Bill");

	wyatt.join();
	buffalo.join();
}

