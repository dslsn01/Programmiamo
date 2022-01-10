/* file esercizio4.cpp */

#include <iostream>

using std::cout;
using std::endl;

int abs(int n) {
	return n >= 0 ? n : -n;
}

int main() 
{
	int i = -7;
	while (i <= 7) {
		cout << abs(i) << " ";
		i++;
	}

	cout << endl;
}

