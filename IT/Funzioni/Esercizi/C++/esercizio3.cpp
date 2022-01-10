/* file esercizio3.cpp */

#include <iostream>

using std::cout;
using std::endl;

int s(int n) {
	return n + 1;
}

int main() 
{
	for (int i = 0; i < 10; i++) {
		cout << s(s(i)) << " ";
	}

	cout << endl;
}

