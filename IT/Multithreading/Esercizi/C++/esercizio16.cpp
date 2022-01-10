/*
file esercizio16.cpp
compilare con: g++ -std=c++11 esercizio16.cpp -lpthread
*/

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using std::cout;
using std::endl;
using std::flush;
using std::ref;
using std::thread;
using std::this_thread::sleep_for;
using std::mutex;
using std::unique_lock;
using std::chrono::duration;
using std::chrono::seconds;

void func(int& v, mutex& _mutex)
{
	unique_lock<mutex> lock(_mutex);

	for (int i = 0; i < 3; i++) {
		v++;
		cout << v << " " << flush; // flush necessario!
		sleep_for(seconds(1));
	}
}

int main()
{
	int v = 0;
	mutex mutex;

	thread threads[3];

	for (int i = 0, j = 0; i < 3; i++, j += 3) {
		threads[i] = thread(func, ref(v), ref(mutex));
	}

	for (thread& t: threads) {
		t.join();
	}

	cout << endl;
}

