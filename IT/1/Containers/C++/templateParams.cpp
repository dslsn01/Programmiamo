/*
file templateParams.cpp
compilare con: g++ -std=c++11 templateParams.cpp
*/

#include <iostream>

using std::cout;
using std::endl;

/* la classe astratta Vehicle definisce il metodo startEngine() */
class Vehicle {
	public:
		virtual void startEngine() = 0;
};

/* la funzione template checkup() può ricevere un puntatore a un generico veicolo come argomento */
class Garage {
	public:
		template<typename T>
		void checkup(T& vehicle);
};

template<typename T>
void Garage::checkup(T& vehicle)
{
	vehicle.startEngine();
}

/* entrambe le classi Car e Moto implementano il metodo startEngine() */
class Car : public Vehicle {
	public:
		void startEngine() override;
};

void Car::startEngine()
{
	cout << "Avvio l'automobile!" << endl;
}

class Moto : public Vehicle {
	public: 
		void startEngine() override;
};

void Moto::startEngine()
{
	cout << "Avvio la moto!" << endl;
}

int main()
{
	Garage garage;

	/* invoca il metodo checkup() e quindi i metodi Car::startEngine() e Moto::startEngine() */

	Car car;
	garage.checkup(car);

	Moto moto;
	garage.checkup(moto);
}

