/* file esercizio4.cpp */

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

	friend ostream& operator<<(ostream&, const Spaceman&);
};

Spaceman::Spaceman(string name)
{
	this->name = name;
}

ostream& operator<<(ostream& os, const Spaceman& s) {
	os << "Sono l'astronauta " << s.name << "!";
	return os;
}

int main()
{
	Spaceman neil("Neil Armstrong");

	// cosa stampa?
	cout << neil << endl;
}

