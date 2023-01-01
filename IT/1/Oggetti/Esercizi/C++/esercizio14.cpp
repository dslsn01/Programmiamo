/* file esercizio14.cpp */

#include <iostream>

using std::string;

class Engine {
	private:
		int cc;

	public:
		Engine(int);
};

class Car {
	private: 
		string model;
		string plate;
		string vin;
		Engine* engine;

	public:
		Car(string, string, string, Engine*);
		~Car();
};

Engine::Engine(int cc) {
	this->cc = cc;
}

Car::Car(string model, string plate, string vin, Engine* engine) {
	this->model = model;
	this->plate = plate;
	this->vin = vin;
	this->engine = engine;
}

Car::~Car() {
	delete engine;
}

int main()
{
}

