/* file inheritance2.cpp */

#include <iostream>

using std::cout;
using std::endl;

class Processor {
	public:
		int x;
	protected:
		int y;
	private:
		int z;

	public:
		Processor();
};

Processor::Processor() {
	this->x = 1;
	this->y = 2;
	this->z = 3;
}

/* un computer ha un processore */

class Computer : private Processor {
	public:
		Computer();
};

Computer::Computer() {
	cout << "Assemblato un nuovo computer!" << endl;
	cout << "x: " << this->x << endl;
	cout << "y: " << this->y << endl;
	// cout << "z: " << this->z << endl;
}

class Notebook : public Computer
{
	/* poichè Computer estende Processor con l'ereditarietà private, i membri definiti in Processor ed ereditati da Computer sono inaccessibili dalle sottoclassi di Computer */

	public:
		Notebook();
};

Notebook::Notebook() {
	// cout << "x: " << this->x << endl;
	// cout << "y: " << this->y << endl;
	// cout << "z: " << this->z << endl;
}

/* un telefono ha un processore */

class Phone : protected Processor {
};

class IPhone : public Phone 
{
	/* poichè la classe Phone estende Processor con l'ereditarietà protected, i membri definiti in Processor ed ereditati da Phone sono inaccessibili anche dalle sottoclassi di Phone, come la classe IPhone */

	public:
		IPhone();
};

IPhone::IPhone() {
	cout << "Assemblato un nuovo IPhone!" << endl;
	cout << "x: " << this->x << endl;
	cout << "y: " << this->y << endl;
	// cout << "z: " << this->z << endl;
}

int main()
{
	/* dichiara un puntatore a un oggetto Processor */

	Processor *p = 0;

	/* la classe Computer estende Processor con l'erediterietà private: un Computer non è un Processor */

	Computer *c = new Computer();

	/* l'ereditarietà private non permette il polimorfismo: è illecito assegnare un oggetto Computer a un puntatore di tipo Processor */

	// p = c;

	delete c;

	/* la classe IPhone estende Processor con l'ereditarietà protected: un oggetto IPhone non è un Processor */

	IPhone *iphone = new IPhone();

	/* l'ereditarietà protected non permette il polimorfismo */

	// p = iphone;

	delete iphone;
}

