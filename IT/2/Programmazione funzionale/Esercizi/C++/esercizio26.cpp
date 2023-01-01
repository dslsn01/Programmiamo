/*
file esercizio26.cpp
compilare con: g++ -std=c++11 (oppure: -std=c++1y) esercizio26.cpp
*/

#include <iostream>
#include <random>
#include <functional>

using std::cout;
using std::endl;
using std::bind;
using std::random_device;
using std::default_random_engine;
using std::uniform_int_distribution;
using namespace std::placeholders;

int f(int a, int b, int c) {
	if (a > b) {
		return a > c ? a : c;
	}
	else {
		return b > c ? b : c;
	}
}

int main() {
	default_random_engine gen(random_device{}());
	uniform_int_distribution<int> dist(1, 10);
	int a = dist(gen);
	int b = dist(gen);
	int c = dist(gen);

	cout << "a=" << a << ", b=" << b << ", c=" << c << endl;

	// calcola il numero maggiore con l'applicazione parziale della funzione originale

	cout << "Trovo il maggiore con l'applicazione parziale: " << endl;

	// h = f(a, ...)

	auto h = bind(f, a, _1, _2);

	cout << "Numero maggiore: " << h(b, c) << endl;

	// i = f(a, b, ...)

	auto i = bind(h, b, _1);

	cout << "Numero maggiore: " << i(c) << endl;

	// funzione lambda che implementa il currying

	auto g = [] (const int a) {
		return [=] (const int b) {
			return [=] (const int c) {
				if (a > b) {
					return a > c ? a : c;
				}
				else {
					return b > c ? b : c;
				}
			};
		};
	};

	cout << "Trovo il maggiore con il currying: " << endl;

	// chiamata di funzione con il currying

	int m = g(a)(b)(c);

	cout << "Numero maggiore: " << m << endl;
}

