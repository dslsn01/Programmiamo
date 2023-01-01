/*
file esercizio20.cpp
compilare con: g++ -std=c++11 esercizio20.cpp
*/

#include <iostream>
#include <functional>

using std::cout;
using std::endl;
using std::function;

int main() {
	// funzione "successore"

	function<int(int)> s = [] (const int n) { return n + 1; };

	// restituisce il successore del successore di un numero

	function<int(function<int(int)>, int)> ff = [] (function<int(int)> f, const int n) { return f(f(n)); };

	// stampa "2"

	cout << "Successore del successore di zero: " << ff(s, 0) << endl;
}

