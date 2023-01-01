/* file templateFunction.cpp */

#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::ostream;

/* la classe Receptionist non è un template di classe, ma include il metodo template registerP() */

class Receptionist {
	public:
		template <typename T>
		void registerP(T& p);
};

template <typename T>
void Receptionist::registerP(T& visitor)
{
	cout << "Registro un " << visitor << "." << endl;
}

class Customer {
	friend ostream& operator<<(ostream &os, const Customer &cstm);
};

class Supplier {
	friend ostream& operator<<(ostream &os, const Customer &cstm);
};

/* ridefinisce l'operatore "<<" per stampare comodamente il tipo dei visitatori sulla console */

ostream& operator<<(ostream &os, const Customer&) {
	os << "cliente";
	return os;
}

ostream& operator<<(ostream &os, const Supplier&) {
	os << "fornitore";
	return os;
}

int main() {
	Receptionist receptionist;

	Customer cstm;
	receptionist.registerP(cstm);

	Supplier suppl;
	receptionist.registerP(suppl);
}

