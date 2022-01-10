/* 
file farm.cpp 
compilare con: g++ -std=c++11 farm.cpp -lpthread
*/

#include <iostream>
#include <random>
#include <chrono>
#include <thread>
#include <condition_variable>

using std::cout;
using std::endl;
using std::ref;
using std::random_device;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::chrono::seconds;
using std::this_thread::sleep_for;
using std::thread;
using std::mutex;
using std::unique_lock;
using std::condition_variable;

void heap(int& bales, mutex& _mutex, condition_variable& condition, const char* tname)
{
	static thread_local default_random_engine gen(random_device{}());

	for (int i = 0; i < 3; i++) {
		unique_lock<mutex> lock(_mutex);

		while (bales > 0)
		{
			condition.wait(lock);
		}

		// pausa da 2 a 4 secondi
		uniform_int_distribution<int> dist(2, 4);
		seconds duration(dist(gen));
		sleep_for(duration);

		bales++;
		cout << tname << ": ci sono " << bales << " balle di fieno." << endl;
		condition.notify_one();
	}
}

void eat(int& bales, mutex& _mutex, condition_variable& condition, const char* tname)
{
	static thread_local default_random_engine gen(random_device{}());

	for (int i = 0; i < 3; i++) {
		unique_lock<mutex> lock(_mutex);

		while (bales == 0)
		{
			condition.wait(lock);
		}

		// pausa da 1 a 3 secondi
		uniform_int_distribution<int> dist(1, 3);
		seconds duration(dist(gen));
		sleep_for(duration);

		bales--;
		cout << tname << ": ci sono " << bales << " balle di fieno." << endl;
		condition.notify_one();
	}
}

int main()
{
	int bales = 0;
	mutex _mutex;
	condition_variable condition;

	thread farmer(heap, ref(bales), ref(_mutex), ref(condition), "contadino");
	thread cow(eat, ref(bales), ref(_mutex), ref(condition), "mucca");

	farmer.join();
	cow.join();
}

