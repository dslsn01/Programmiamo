/* file staticMembers.cpp */

#include <iostream>

using std::string;
using std::cout;
using std::endl;

class IPad {
	/* dichiara una variabile membro statica */
	private:
		static int counter;
		string model;

	public:
		/* dichiara una funzione membro statica */
		static int getCounter();
		IPad(string model);
		void setModel(string model);
		string getModel();
};

/* notare la sintassi per inizializzare la variabile statica */
int IPad::counter = 0;

int IPad::getCounter()
{
	return IPad::counter;
}

IPad::IPad(string model) {
	setModel(model);
	IPad::counter++;
}

void IPad::setModel(string model) {
	this->model = model;
}

string IPad::getModel() {
	return this->model;
}

int main()
{
	IPad ipad1("Apple IPad Pro");
	IPad ipad2("Apple IPad Mini 2");
	IPad ipad3("Apple IPad Air");

	cout << "Prodotto " << ipad1.getModel() << "." << endl;
	cout << "Prodotto " << ipad2.getModel() << "." << endl;
	cout << "Prodotto " << ipad3.getModel() << "." << endl;

	cout << "Sono stati prodotti " << IPad::getCounter() << " pezzi in totale." << endl;
}

