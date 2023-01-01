/*
file esercizio16.cpp
compilare con: g++ -std=c++11 esercizio16.cpp
*/

#include <iostream>
#include <iterator>

using std::cout;
using std::endl;
using std::ostream_iterator;
using std::begin;
using std::end;

int main()
{
	int numbers[] = {1, 3, 5, 7, 9};
	int val = 10;
	const int LEN = sizeof(numbers) / sizeof(int);

	copy(begin(numbers), end(numbers), ostream_iterator<int>(cout, " "));
	cout << endl;

	for (int i = 0; i < LEN; i++) {
		for (int j = i+1; j < LEN; j++) {
			if (numbers[i] + numbers[j] == val) {
				cout << numbers[i] << " + " << numbers[j] << " = " << val << endl;
			}
		}
	}
}

