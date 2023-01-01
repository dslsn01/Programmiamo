/* file esercizio3.cpp */

#include <iostream>

using std::cout;
using std::endl;
using std::ostream;

class Spaceman {
	friend ostream& operator<<(ostream&, const Spaceman&);
};

ostream& operator<<(ostream &os, const Spaceman& spaceman) {
	os << "Sono un astronauta!";
	return os;
}

int main()
{
	Spaceman neil;

	// cosa stampa?
	cout << neil << endl;
}

