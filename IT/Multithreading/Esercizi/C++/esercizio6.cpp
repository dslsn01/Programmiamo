/*
file esercizio6.cpp
compilare con: g++ -std=c++11 esercizio6.cpp -lpthread
*/

#include <iostream>
#include <iterator>
#include <thread>

using std::cin;
using std::cout;
using std::endl;
using std::copy;
using std::ostream_iterator;
using std::thread;

void func(int index, int *arr) {
	arr[index] *= 2;
}

int main()
{
	// const obbligatorio
	const int N_THREADS = 10;
	int arr[N_THREADS];

	for (int i = 0, j = 1; i < N_THREADS; i++, j++) {
		arr[i] = j;
	}

	thread threads[N_THREADS];

	for (int i = 0; i < N_THREADS; i++) {
		threads[i] = thread(func, i, arr);
	}

	for (auto &thread : threads) {
		thread.join();
	}

	copy(arr, arr+N_THREADS, ostream_iterator<int>(cout, " "));
	cout << endl;
}

