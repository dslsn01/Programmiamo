/* file ptrOwnership.cpp */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::fill;

int* read() {
	cout << "read() - lettura dati." << endl;
	int* data = new int[256]();
	return data;
}

void process(int** data)
{
	cout << "process() - elaborazione dati." << endl;
	fill(*data, *data+10, 1);

	for (int i = 0; i < 10; i++) {
		cout << *(*data + i) << " ";
	}

	cout << endl << "process() - cancellazione dati." << endl;
	delete *data;
	*data = NULL;
}

int main()
{
	cout << "main() - inizio." << endl;

	int *data = read();

	for (int i = 0; i < 10; i++) {
		cout << *(data + i) << " ";
	}

	cout << endl;

	/* la funzione process() dovrebbe avere la proprietà esclusiva dei dati, e libera la memoria dopo aver finito il suo lavoro */

	process(&data);

	if (data == NULL) {
		cout << "main() - fine: dati già cancellati." << endl;
	}
}

