/*
file factory.cpp
compilare con: g++ -std=c++11 factory.cpp -lpthread
*/

#include <iostream>
#include <list>
#include <future>

using std::cout;
using std::endl;
using std::list;
using std::async;
using std::future;

/* classe che rappresenta una componente di un elicottero */

class Part {
	private:
		const char* name;

	public:
		Part(const char*);
		void setName(const char*);
		const char* getName();
};

Part::Part(const char* name) {
	setName(name);
}

void Part::setName(const char* name) {
	this->name = name;
}

const char* Part::getName() {
	return this->name;
}

/* funzione che assembla una singola parte di elicottero */

Part* assemble(const char* type) {
	return new Part(type);
}

int main() 
{
	const char* t[] = {"elica", "motore", "carrello di atterraggio", "telaio", "parabrezza", "cloche", "sedile"};
	const int N_WORKERS = 7;

	list<future<Part*>> parts;

	for (int i = 0; i < N_WORKERS; i++) {
		future<Part*> part = async(std::launch::async, assemble, t[i]);
		parts.push_back(move(part));
	}

	for (auto it = parts.begin(); it != parts.end(); ++it) {
		Part *p = (*it).get();
		cout << "Assemblato -> " << p->getName() << "." << endl;
		delete p;
	}

	cout << "Montiamo l'elicottero pronto al decollo!" << endl;
}

