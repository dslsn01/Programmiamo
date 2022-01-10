/*
file testEnum.cpp
compilare con: g++ -std=c++11 testEnum.cpp
*/

#include <iostream>
#include <random>

using std::cout;
using std::endl;
using std::random_device;
using std::default_random_engine;
using std::uniform_int_distribution;

enum Color {
	RED,
	YELLOW,
	GREEN
};

int main()
{
	/* inizializza casualmente il colore del semaforo */

	default_random_engine gen(random_device{}());
	uniform_int_distribution<int> dist(0, 2);
	int currentColor = dist(gen);

	/* necessaria la conversione di tipo da intero a enumerazione */

	Color semaphore = static_cast<Color>(currentColor);

	/* confronta il colore del semaforo con tutti i colori possibili */

	switch (semaphore)
	{
		case RED:
			cout << "Semaforo ROSSO: fermati!" << endl;
			break;
		case YELLOW:
			cout << "Semaforo GIALLO o lampeggiante: prudenza." << endl;
			break;
		case GREEN:
			cout << "Semaforo VERDE: passa senza problemi..." << endl;
			break;
		default:
			cout << "Semaforo guasto?" << endl;
	}
}

