/*
file esercizio18.cpp
compilare con: g++ -std=c++11 esercizio18.cpp
*/

#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::to_string;

class Engine {
	private:
		int cc;

	public:
		Engine(int);
		string str() const;
};

Engine::Engine(int cc) {
	this->cc = cc;
}

string Engine::str() const {
	return "motore di " + to_string(this->cc) + " centimetri cubi";
}

class Vehicle {
	private:
		Engine *engine;

	public:
		Vehicle(Engine*);
		~Vehicle();
		Engine* getEngine() const;
		void setEngine(Engine*);
		virtual string str() const = 0;

	friend ostream& operator<<(ostream &os, const Vehicle&);
};

ostream& operator<<(ostream &os, const Vehicle& v) {
	os << v.str();
	return os;
}

Vehicle::Vehicle(Engine *e) {
	this->setEngine(e);
}

Vehicle::~Vehicle() {
	delete this->engine;
}

Engine* Vehicle::getEngine() const {
	return this->engine;
}

void Vehicle::setEngine(Engine* engine) {
	this->engine = engine;
}

class Car : public Vehicle {
	private:
		string model;
		string plate;
		string vin;

	public:
		Car(string, string, string, Engine *);

		void setModel(string);
		string getModel();
		void setPlate(string);
		string getPlate();
		void setVin(string);
		string getVin();
		string str() const override;
};

Car::Car(string model, string plate, string vin, Engine *engine) : Vehicle(engine) {
	setModel(model);
	setPlate(plate);
	setVin(vin);
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

string Car::str() const {
	return this->model + ", targa \"" + this->plate + "\", n. telaio \"" + this->vin + "\", " + this->getEngine()->str();
}

class Truck : public Vehicle {
	public:
		Truck(Engine*);
		string str() const override;
};

Truck::Truck(Engine* e) : Vehicle(e) {}

string Truck::str() const {
	return "Camion con " + this->getEngine()->str();
}

class Tractor : public Vehicle {
	public:
		Tractor(Engine*);
		string str() const override;
};

Tractor::Tractor(Engine* e) : Vehicle(e) {}

string Tractor::str() const {
	return "Trattore con " + this->getEngine()->str();
}

int main()
{
	Car fiat500("Fiat 500", "AS 123 DF", "1G8AN12F04Z242828", new Engine(1400));
	Car classeA("Mercedes Classe A", "CA 128 TD", "2FZHAZBD21AH02482", new Engine(1600));
	Car alfaGiulia("Alfa Romeo Giulia", "EE 119 CA", "2G1115SL7F9174905", new Engine(2000));

	cout << fiat500 << endl;
	cout << classeA << endl;
	cout << alfaGiulia << endl;

	Truck truck(new Engine(15000));
	Tractor tractor(new Engine(5800));

	cout << truck << endl;
	cout << tractor << endl;
}

