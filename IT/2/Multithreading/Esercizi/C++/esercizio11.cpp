/*
file esercizio11.cpp
compilare con: g++ -std=c++11 esercizio11.cpp -lpthread
*/

#include <thread>
#include <iostream>

using std::cout;
using std::endl;
using std::thread;
using std::fixed;

void func(double *v, double value, int pos) {
	v[pos] *= value;
}

int main()
{
	double v[3] = { 1.0, 2.0, 3.0 };

	cout.precision(1);

	for (auto &i : v) {
		cout << fixed << i << " ";
	}

	cout << endl;

	double scalar = 2.0;

	thread threads[3];

	for (int i = 0; i < 3; i++) {
		threads[i] = thread(func, v, scalar, i);
	}

	for (thread& t: threads) {
		t.join();
	}

	for (auto& i : v) {
		cout << fixed << i << " ";
	}

	cout << endl;
}

