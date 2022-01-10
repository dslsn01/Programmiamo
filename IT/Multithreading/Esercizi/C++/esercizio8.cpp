/*
file esercizio8.cpp
compilare con: g++ -std=c++11 esercizio8.cpp -lpthread
*/

#include <iostream>
#include <iterator>
#include <future>

using std::cin;
using std::cout;
using std::endl;
using std::copy;
using std::ostream_iterator;
using std::async;
using std::future;

void func(int index, int *arr) {
	arr[index] *= arr[index];
}

int main()
{
	// const obbligatorio
	const int N_THREADS = 10;
	int arr[N_THREADS];

	for (int i = 0, j = 1; i < N_THREADS; i++, j++) {
		arr[i] = j;
	}

	for (int i = 0; i < N_THREADS; i++) {
		async(std::launch::async, func, i, arr);
	}

	copy(arr, arr+N_THREADS, ostream_iterator<int>(cout, " "));
	cout << endl;
}

