/*
file esercizio20.cpp
compilare con: g++ -std=c++11 esercizio20.cpp
*/

#include <iostream>
#include <unordered_map>

using std::cout;
using std::endl;
using std::string;
using std::boolalpha;
using std::hash;
using std::unordered_map;
using std::ostream;

/* la classe Employee rappresenta un'impiegato di un'azienda */

class Employee {
	/* ogni impiegato ha nome, cognome e numero di badge */
	private:
		string name;
		string surname;
		int badge;

	public:
		Employee(string, string, int);
	
	friend bool operator==(const Employee&, const Employee&);
	friend ostream& operator<<(ostream&, const Employee&);
	friend class Hash;
};

Employee::Employee(string name, string surname, int badge) {
	this->name = name;
	this->surname = surname;
	this->badge = badge;
}

ostream& operator<<(ostream& os, const Employee& e) {
	return os << e.name << " " << e.surname << ", badge numero=" << e.badge << ".";
}

/* due impiegati sono uguali se e solo se hanno lo stesso badge, quindi sono la stessa persona */

bool operator==(const Employee &e1, const Employee &e2) {
	return e1.badge == e2.badge;
}

/* il nuovo operatore () restituisce l'hash di tutte le variabili membro */

struct Hash {
	size_t operator()(const Employee &e) const {
		const int prime = 31;
		int result = 1;
		/* calcola l'hash complessivo di tutte le variabili membro, e moltiplica il risultato per una costante prima */
		size_t name = hash<string>()(e.name);
		size_t surname = hash<string>()(e.surname);
		size_t badge = hash<int>()(e.badge);

		size_t propertyHash = name ^ (surname << 2) ^ (badge >> 2);

		result = prime * result + propertyHash;
		return result;
	}
};

int main()
{
	Employee e1("Mario", "Rossi", 1000);
	Employee e2("Luigi", "Bianchi", 1001);
	Employee e3("Luigi", "Bianchi", 1001);

	cout << e1 << endl;
	cout << e2 << endl;
	cout << e3 << endl;

	cout << "Il primo e il secondo impiegato sono la stessa persona? " << boolalpha << (e1 == e2) << endl;
	cout << "Il secondo e il terzo impiegato sono la stessa persona? " << boolalpha << (e2 == e3) << endl;
}

