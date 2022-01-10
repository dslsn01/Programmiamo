/* 
file smartPtrOwnership.cpp
compilare con: g++ -std=c++11 smartPtrOwnership.cpp
*/

#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::fill;
using std::unique_ptr;
using std::move;

unique_ptr<int[]> read() {
	cout << "read() - lettura dati." << endl;
	unique_ptr<int[]> data(new int[10]);
	return data;
}

void process(unique_ptr<int[]> data) {
	cout << "process() - elaborazione dati." << endl;
	fill(data.get(), data.get()+10, 1);

	for (int i = 0; i < 10; i++) {
		cout << data[i] << " ";
	}

	cout << endl << "process() - cancellazione dati." << endl;
}

int main()
{
	cout << "main() - inizio." << endl;

	unique_ptr<int[]> data = read();

	for (int i = 0; i < 10; i++) {
		cout << data[i] << " ";
	}

	cout << endl;

	// la funzione process() dovrebbe avere la proprietà esclusiva dei dati, e libera la memoria dopo aver finito il suo lavoro

	process(move(data));

	// a questo punto l'unique_ptr non c'è più

	if (data == nullptr) {
		cout << "main() - fine: dati già cancellati." << endl;
	}
}

