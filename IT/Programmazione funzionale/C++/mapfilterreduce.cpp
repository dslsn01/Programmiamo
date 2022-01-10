/*
file mapfilterreduce.cpp
compilare con: g++ -std=c++11 mapfilterreduce.cpp
*/

#include <iostream>
#include <iomanip>
#include <iterator>
#include <algorithm>
#include <vector>
#include <random>

using std::cout;
using std::endl;
using std::setprecision;
using std::ostream_iterator;
using std::random_device;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::generate;
using std::greater;
using std::vector;

int main() {
	default_random_engine gen(random_device{}());
	uniform_int_distribution<int> dist(1, 100);

	vector<int> v(200);
	generate(v.begin(), v.end(), [&dist, &gen]() { return dist(gen); });

	// converte tutti i voti in centesimi in voti in trentesimi

	vector<int> li(v.size());
	transform(v.begin(), v.end(), li.begin(), [](const int n) { return round((double)n*30/100); } );

	// seleziona tutti e soli gli studenti che hanno passato l'esame

	vector<int> app;
	copy_if(li.begin(), li.end(), back_inserter(app), [](const int n) { return n >= 18; });

	// ordina i voti dal maggiore al minore

	vector<int> sorted(app.size());
	partial_sort_copy(app.begin(), app.end(), sorted.begin(), sorted.end(), greater<int>());

	cout << "----- Voti sufficienti -----" << endl;
	cout << "[";
	copy(sorted.begin(), sorted.end(), ostream_iterator<int>(cout, ", "));
	cout << "\b\b]" << endl;

	cout << "-------- RIASSUNTO ---------" << endl;
	cout << app.size() << " studenti su " << li.size() << " hanno passato la prova d'esame." << endl;

	int bp = count(app.begin(), app.end(), 30);
	cout << bp << " studenti hanno ottenuto il voto massimo." << endl;

	// calcola il voto medio di superamento dell'esame
	double mv = (double) accumulate(app.begin(), app.end(), 0) / app.size();

	cout << setprecision(3) << "Voto medio: " << mv << endl;
}

