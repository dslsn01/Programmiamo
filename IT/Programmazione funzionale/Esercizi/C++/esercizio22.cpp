/*
file esercizio22.cpp
compilare con: g++ -std=c++11 esercizio22.cpp
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::vector;

struct Title {
	string title;
	string auth;
	int yr;
};

int main() {
	vector<Title> b = {{"De Arte Combinatoria", "Gottfried Wilhelm Leibniz", 1666}, {"Discorso sulla Metafisica", "Gottfried Wilhelm Leibniz", 1686}, {"Sulla strada", "Jack Kerouac", 1957}, {"Il Libro dei Sogni", "Jack Kerouac", 1960}, {"Sessanta racconti", "Dino Buzzati", 1958}, {"Il deserto dei Tartari", "Dino Buzzati", 1940}, {"Un amore", "Dino Buzzati", 1963}, {"Zanna bianca", "Jack London", 1906}};

	vector<Title> b2;

	copy_if(b.begin(), b.end(), inserter(b2, b2.begin()), [](const Title& t) {
		return t.auth == "Dino Buzzati";
	});

	vector<Title> b3(b2.size());
	partial_sort_copy(b2.begin(), b2.end(), b3.begin(), b3.end(), [] (const Title& t1, const Title& t2) {
		return t1.yr > t2.yr;
	});

	vector<string> s;
	transform(b3.begin(), b3.end(), inserter(s, s.begin()), [] (const Title& t) {
		return "\"" + t.title + "\", " + t.auth + " (" + to_string(t.yr)  + ")";
	});

	string str = accumulate(s.begin(), s.end(), string(), [] (string& result, const string& b) {
		return !result.empty() ? result + "\n" + b : b;
	});

	cout << str << endl;
}

