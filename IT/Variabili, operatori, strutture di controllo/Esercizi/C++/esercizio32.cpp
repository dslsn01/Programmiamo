/* 
file esercizio32.cpp
compilare con: g++ esercizio32.cpp
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	for (int i = 1; i <= 30; i++) {
		if (i % 5 == 0 & i % 3 == 0) {
			cout << "fizzbuzz ";
		}
		else if (i % 3 == 0) {
			cout << "fizz ";
		}
		else if (i % 5 == 0) {
			cout << "buzz ";
		}
		else {
			cout << i << " ";
		}
	}

	cout << endl;
}

