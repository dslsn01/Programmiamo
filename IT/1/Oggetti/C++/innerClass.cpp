/*
file innerClass.cpp
compilare con: g++ -std=c++11 innerClass.cpp 
*/

#include <iostream>
#include <random>

using std::cout;
using std::endl;
using std::random_device;
using std::default_random_engine;
using std::uniform_int_distribution;

/* la classe Sprinkler rappresenta un sistema antincendio */
class Sprinkler 
{
	private:
	/* la classe HeatDetector rappresenta un sistema di rilevamento temperatura */
	class HeatDetector {
		public:
			bool heatControl(int ht);
	};

/* Il sistema antincendio possiede un rilevatore di temperatura interno */
	private:
		HeatDetector *heatDetector;

	public:
		Sprinkler();
		virtual ~Sprinkler();
		bool fire(int);
};

/* se la temperatura supera i 70 gradi C, potrebbe esserci un incendio */
bool Sprinkler::HeatDetector::heatControl(int ht) {
	cout << "Temperatura rilevata: " << ht << " gradi C."  << endl;
	return ht >= 70 ? true : false;
}

Sprinkler::Sprinkler() {
	this->heatDetector = new HeatDetector();
}

Sprinkler::~Sprinkler() {
	delete this->heatDetector;
}

/* controlla la temperatura, e nel caso suona l'allarme */
bool Sprinkler::fire(int ht) {
	bool fire = this->heatDetector->heatControl(ht);
	if (fire) {
		cout << "Possibile incendio!" << endl << "I passeggeri sono invitati a raggiungere l'uscita di sicurezza più vicina." << endl;
	}
	return fire;
}

int main()
{
	Sprinkler *sprinkler = new Sprinkler();

	default_random_engine gen(random_device{}());
	uniform_int_distribution<int> dist(18, 100);

	/* controlla periodicamente la temperatura della metropolitana */
	while (true) {
		int ht = dist(gen);
		if (sprinkler->fire(ht)) {
			break;
		}
	}

	delete sprinkler;
}

