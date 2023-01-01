/* file esercizio5.cpp */

#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::ostream;

class Spaceman {
	private:
		string name;

	public:
		Spaceman(string);
		string getName();
		void setName(string);

	friend ostream& operator<<(ostream&, const Spaceman&);
};

Spaceman::Spaceman(string name)
{
	this->setName(name);
}

string Spaceman::getName() {
	return this->name;
}

void Spaceman::setName(string name) {
	this->name = name;
}

ostream& operator<<(ostream& os, const Spaceman& s) {
	os << "Sono l'astronauta " << s.name << "!";
	return os;
}

int main()
{
	Spaceman neil("Neil Armstrong");
	cout << neil << endl;
}

