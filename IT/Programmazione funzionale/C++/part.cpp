/*
file part.cpp
compilare con: g++ -std=c++11 part.cpp
*/

#include <iostream>
#include <functional>

using std::cout;
using std::endl;
using std::bind;
using namespace std::placeholders;

int main() {
	// funzione che calcola la percentuale, ad es. il 30% di 100
	auto percent = [] (const int x, const int y) { return (double) x / 100 * y; };

	// calcola il 60% di 120: invoca la funzione con entrambi i parametri
	cout << "60% di 120 = " << percent(120, 60) << endl;

	// applicazione parziale della funzione: fissa il primo parametro al variare del secondo

	auto part = bind(percent, 70, _1);

	cout << "30% di 70 = " << part(30) << endl;
	cout << "60% di 70 = " << part(60) << endl;
	cout << "90% di 70 = " << part(90) << endl;
}

