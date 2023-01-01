/* file esercizio15.cpp */

#include <iostream>

using std::string;

class Engine {
	private:
		int cc;

	public:
		Engine(int);
};

Engine::Engine(int cc) {
	this->cc = cc;
}

class Car {
	private:
		string model;
		string plate;
		string vin;
		Engine* engine;

	public:
		Car(string, string, string, Engine*);
		~Car();

		void setModel(string);
		string getModel();
		void setPlate(string);
		string getPlate();
		void setVin(string);
		string getVin();
		Engine* getEngine();
		void setEngine(Engine*);
};

Car::Car(string model, string plate, string vin, Engine* engine) {
	setModel(model);
	setPlate(plate);
	setVin(vin);
	setEngine(engine);
}

Car::~Car() {
	delete engine;
}

string Car::getModel() {
	return this->model;
}

void Car::setModel(string model) {
	this->model = model;
}

string Car::getPlate() {
	return this->plate;
}

void Car::setPlate(string plate) {
	this->plate = plate;
}

string Car::getVin() {
	return this->vin;
}

void Car::setVin(string vin) {
	this->vin = vin;
}

Engine* Car::getEngine() {
	return this->engine;
}

void Car::setEngine(Engine* engine) {
	this->engine = engine;
}

int main()
{
}

