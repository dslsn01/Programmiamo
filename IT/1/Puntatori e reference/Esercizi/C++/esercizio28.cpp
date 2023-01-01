/*
file esercizio28.cpp
compilare con: g++ -std=c++11 esercizio28.cpp
*/

#include <iostream>
#include <stdlib.h>
#include <memory>

using std::cout;
using std::endl;
using std::shared_ptr;
using std::weak_ptr;

struct Pilot;

struct Biplane {
	shared_ptr<Pilot> pilot;

	Biplane() {
		cout << "Nuovo aereo in pista!" << endl;
	}

	~Biplane() {
		cout << "L'aereo si è schiantato al suolo." << endl;
	}
};

struct Pilot {
	weak_ptr<Biplane> aereo;
	Pilot() {
		cout << "Il barone rosso è pronto al decollo." << endl;
	}

	~Pilot() {
		cout << "Il pilota si lancia dall'aereo in fiamme." << endl;
	}
};

int main()
{
	shared_ptr<Biplane> biplane(new Biplane());
	shared_ptr<Pilot> pilot(new Pilot());

	biplane->pilot = pilot;
	pilot->aereo = biplane;
}

