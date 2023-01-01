/*
file moveSem.cpp
compilare con: g++ -std=c++11 moveSem.cpp
*/

#include <iostream>
#include <list>
#include <iterator>

using std::cout;
using std::endl;
using std::list;
using std::move;
using std::copy;
using std::ostream;

class VectorNd {
	private:
		int n;
		double *values;
	public:
		VectorNd() = default;
		VectorNd(const int);
		// costruttore di copia
		VectorNd(const VectorNd&);
		// costruttore di spostamento
		VectorNd(VectorNd&&);
		~VectorNd();

	VectorNd& operator=(VectorNd&&);
	friend std::ostream& operator<<(std::ostream&, const VectorNd&);
};

VectorNd::VectorNd(const int n) {
	cout << "(Costruttore)" << endl;
	this->n = n;
	this->values = new double[n];
}

VectorNd::VectorNd(const VectorNd& v) {
	cout << "(Costruttore di copia)" << endl;
	this->n = v.n;
	this->values = new double[this->n];
	copy(v.values, v.values + v.n, this->values);
}

VectorNd::VectorNd(VectorNd&& v) {
	cout << "<Costruttore di spostamento>" << endl;
	this->n = v.n;
	this->values = new double[this->n];
	copy(v.values, v.values + v.n, this->values);
	v.n = 0;
	delete [] v.values;
	v.values = nullptr;
}

VectorNd::~VectorNd() {
	cout << "[Distruttore]" << endl;
	delete [] this->values;
	this->values = nullptr;
}

VectorNd& VectorNd::operator=(VectorNd&& v) {
	cout << "<Operatore di assegnazione e spostamento>" << endl;
	if (this == &v) return *this;
	this->n = v.n;
	this->values = new double[this->n];
	copy(v.values, v.values + v.n, this->values);
	v.n = 0;
	delete [] v.values;
	v.values = nullptr;
	return *this;
}

ostream& operator<<(ostream &os, const VectorNd& v) {
	if (v.n) {
		os << "(";
		for (int i = 0; i < v.n; i++) {
			os << v.values[i] << ", ";
		}
		os << "\b\b)";
	}
	else {
		os << "<Vettore non valido>";
	}
	return os;
}

int main() {
	VectorNd v1(3);
	cout << "v1 = " << v1 << endl;

	// in alternativa si può usare l'operatore di assegnazione e spostamento
	// VectorNd v2;
	// v2 = move(v1);

	list<VectorNd> coords;
	coords.push_back(move(v1));

	// dopo lo spostamento, il vettore originale è "vuoto"
	cout << "v1 = " << v1 << endl;
}

