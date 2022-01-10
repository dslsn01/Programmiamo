/* file esercizio1.cpp */

#include <iostream>

using std::cout;
using std::endl;

int id(int n) {
	return n;
}

int main() 
{
	for (int i = 1; i <= 3; i++) {
		cout << "id(" << i << ") = " << id(i) << " " << endl;
	}
}

