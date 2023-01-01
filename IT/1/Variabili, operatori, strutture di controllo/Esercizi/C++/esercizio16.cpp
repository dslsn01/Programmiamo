/* file esercizio16.cpp */

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	const int M = 10;
	const int N = 10;

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cout << (i * j) << "\t";
		}
		cout << endl;
	}
}

