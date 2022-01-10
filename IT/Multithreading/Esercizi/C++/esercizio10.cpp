/*
file esercizio10.cpp
compilare con: g++ -std=c++11 esercizio10.cpp -lpthread
*/

#include <thread>
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::fill;
using std::thread;

void func(int *arr, int start, int end) {
	for (int i = start; i < end; i++) {
		arr[i] = i + 1;
	}
}

int main()
{
	int arr[9];

	fill(arr, arr + 9, 0);

	for (auto &i : arr) {
		cout << i << " ";
	}

	cout << endl;

	thread threads[3];

	for (int i = 0, j = 0; i < 3; i++, j += 3) {
		threads[i] = thread(func, arr, j, j+3);
	}

	for (thread& t: threads) {
		t.join();
	}

	for (auto& i : arr) {
		cout << i << " ";
	}

	cout << endl;
}

