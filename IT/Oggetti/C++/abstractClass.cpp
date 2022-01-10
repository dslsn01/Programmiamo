/*
file abstractClass.cpp
compilare con: g++ -std=c++11 abstractClass.cpp
*/

#include <iostream>

using std::cout;
using std::endl;

class Vehicle
{
	/* la classe astratta Vehicle dichiara il metodo astratto start(), che dovrà essere implementato dalle sottoclassi */

	public:
		virtual void start()=0;

		void turn();
};

void Vehicle::turn()
{
	cout << "Cambio di direzione!" << endl;
}

/* la classe concreta Train estende la classe astratta Vehicle e implementa la funzione astratta start() */

class Train : public Vehicle {
	public:
		void start() override;
};

void Train::start() 
{
	cout << "Partenza dal binario 1!" << endl;
}

/* la classe concreta Aircraft estende la classe astratta Vehicle e implementa la funzione membro astratta start() */

class Aircraft : public Vehicle {
	public:
		void start() override;
};

void Aircraft::start() 
{
	cout << "Decollo dalla pista!" << endl;
}

int main()
{
	Train train;
	train.start();
	train.turn();

	Aircraft jumbo;
	jumbo.start();
	jumbo.turn();
}

