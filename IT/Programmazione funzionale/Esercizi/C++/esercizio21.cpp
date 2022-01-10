/*
file esercizio21.cpp
compilare con: g++ -std=c++11 esercizio21.cpp
*/

#include <iostream>
#include <functional>
#include <cmath>

using std::cout;
using std::endl;
using std::function;

function<double(double)> compose(function<double(double)> g, function<double(double)> f) {
	return [g, f] (double x) { return g(f(x)); };
}

int main() {
	function<double(double)> f = [] (double x) { return exp(x); };
	function<double(double)> g = [] (double y) { return y + 1; };

	function<function<double(double)>(function<double(double)> g, function<double(double)> f)> k = [] (function<double(double)> g, function<double(double)> f) {
		return [g, f] (double x) { return g(f(x)); };
	};

	// funzione composta (g o f)(x) = e^x + 1

	function<double(double)> gof = k(g, f);

	cout << "e^3 + 1 = " << gof(3.0) << endl;
}

