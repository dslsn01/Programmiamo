/*
file weakPtr.cpp
compilare con: g++ -std=c++11 weakPtr.cpp
*/

#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;
using std::make_shared;
using std::weak_ptr;

/* dichiarazione anticipata della struttura */

struct Engine;

struct Car {
	string model;
	shared_ptr<Engine> engine;

	Car() : model("Ferrari F458") {}
	~Car() {
		cout << "Automobile demolita." << endl;
	} 
}; 

struct Engine { 
	// shared_ptr<Car> parent;
	weak_ptr<Car> parent;

	~Engine() {
		cout << "Motore smontato." << endl;
	} 
};

int main()
{ 
	/* riferimento ciclico: un'automobile contiene un motore, e un motore contiene un riferimento all'automobile */

	shared_ptr<Engine> engine = make_shared<Engine>();
	shared_ptr<Car> car = make_shared<Car>();

	car->engine = engine;
	engine->parent = car;

	cout << "Modello di automobile: " << car->model << "." << endl;
	cout << "Motore montato sull'automobile " << engine->parent.lock()->model << "." << endl; 
}

