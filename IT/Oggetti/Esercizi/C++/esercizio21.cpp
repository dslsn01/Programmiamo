/* file esercizio21.cpp */

#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::ostream;

class Smartphone {
	private:
		string model;

	public:
		Smartphone(string);

	friend ostream& operator<<(ostream&, const Smartphone&);
};

Smartphone::Smartphone(string model) {
	this->model = model;
}

ostream& operator<<(ostream& os, const Smartphone& smartphone) {
	return os << smartphone.model;
}

class Factory {
	private:
		static int instances;

	public:
		static int getInstances();
		static Smartphone* newSmartphone(string);
};

int Factory::instances = 0;

int Factory::getInstances() {
	return instances;
}

Smartphone* Factory::newSmartphone(string model) {
	instances += 1;
	return new Smartphone(model);
}

int main() {
	Smartphone* iphone = Factory::newSmartphone("iPhone");
	Smartphone* samsung = Factory::newSmartphone("Samsung");
	Smartphone* huawei = Factory::newSmartphone("Huawei");

	cout << "Prodotti " << Factory::getInstances() << " nuovi smartphone." << endl;

	cout << *iphone << endl;
	cout << *samsung << endl;
	cout << *huawei << endl;

	delete iphone;
	delete samsung;
	delete huawei;
}

