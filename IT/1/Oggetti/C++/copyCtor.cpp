/*
file copyCtor.cpp
compilare con: g++ -std=c++11 testCopyCtor.cpp
*/

#include <iostream>
#include <ostream>
#include <unordered_map>

using std::ostream;
using std::unordered_map;
using std::string;
using std::cout;
using std::endl;

class Student {
	public:
		string name;
		string matr;
		string cdl;
		unordered_map<string, int> es;

	public:
		Student() = default;
		Student(const char*, const char*, const char*);
		// costruttore di copia
		Student(const Student& s);
		void unilib();

	Student& operator=(const Student&);
	friend std::ostream& operator<<(std::ostream&, const Student&);
};

Student::Student(const char* name, const char* matr, const char* cdl) : es {{"Architettura degli elaboratori", -1},  {"Programmazione", -1}, {"Calcolo 1", -1}} {
	this->name = name;
	this->matr = matr;
	this->cdl = cdl;
}

Student::Student(const Student& s) {
	this->name = s.name;
	this->matr = s.matr;
	this->cdl = s.cdl;
	this->es = s.es;
}

Student& Student::operator=(const Student& s) {
	if (this == &s) return *this;
	this->name = s.name;
	this->matr = s.matr;
	this->cdl = s.cdl;
	this->es = s.es;
	return *this;
}

ostream& operator<<(ostream &os, const Student& s) { 
	os << s.name << ", matricola " << s.matr << ", corso di laurea in " << s.cdl << "."; 
	return os;
}

void Student::unilib() {
	int _pass = 0;
	for (auto& p : this->es) {
		string k = p.first;
		int v = p.second;
		if (v != -1) {
			cout << this->name << " (" << this->matr << ") ha superato l'esame \"" << k << "\" con il voto " << v << "." << endl;
			_pass++;
		}
	}
}

int main() {
	Student s1("Mario Rossi", "A23234", "Scienze dell'Informazione");

	// crea un nuovo studente con il costruttore di copia
	Student s2 = s1;

	// in alternativa si può usare l'operatore di copia e assegnamento
	// Student s2;
	// s2 = s1;

	s2.matr = "A01357";
	s2.cdl = "Ingegneria Informatica";
	s2.es["Programmazione"] = 30;
	cout << s1 << endl;
	cout << s2 << endl;
	s1.unilib();
	s2.unilib();
}

