/* file esercizio16.cpp */

#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::ostream;

class Engine {
	private:
		int cc;

	public:
		Engine(int);

	friend ostream& operator<<(ostream&, const Engine&);
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

	friend ostream& operator<<(ostream&, const Car&);
};

ostream& operator<<(ostream &os, const Engine& engine) {
	os << "motore di " << engine.cc << " centimetri cubi";
	return os;
}

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

ostream& operator<<(ostream &os, const Car& car) {
	os << car.model << ", targa: " << car.plate << ", n. telaio: " << car.vin << ", " << *car.engine << ".";
	return os;
}

int main()
{
	Car fiat500("Fiat 500", "AS 123 DF", "1G8AN12F04Z242828", new Engine(1400));
	Car classeA("Mercedes Classe A", "CA 128 TD", "2FZHAZBD21AH02482", new Engine(1600));
	Car alfaGiulia("Alfa Romeo Giulia", "EE 119 CA", "2G1115SL7F9174905", new Engine(2000));

	cout << fiat500 << endl;
	cout << classeA << endl;
	cout << alfaGiulia << endl;
}

