/*
file esercizio25.cpp
compilare con: g++ -std=c++11 esercizio25.cpp
*/

#include <iostream>
#include <functional>

using std::cout;
using std::endl;
using std::bind;
using namespace std::placeholders;

int main() {
	auto f = [] (const int a, const int b) { return a + b; };

	cout << "3 + 3 = " << f(3, 3) << endl;

	auto g = bind(f, 0, _1);

	cout << "id(3) = " << g(3) << endl;

	auto h = [] (const int a, const int b) { return a - b; };

	cout << "3 - 2 = " << h(3, 2) << endl;

	// calcola l'elemento inverso

	auto i = bind(h, 0, _1);

	cout << "Inverso additivo di 3 = " << i(3) << endl;
}

