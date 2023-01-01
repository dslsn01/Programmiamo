/* 
file hashing.cpp
compilare con: g++ -std=c++11 hashing.cpp 
*/

#include <iostream>
#include <unordered_map>

using std::string;
using std::cout;
using std::endl;
using std::boolalpha;
using std::ostream;
using std::hash;
using std::unordered_map;

/* la classe Car rappresenta un'automobile */

class Car {
	/* identifichiamo ogni auto dal numero di telaio e dal numero di targa */
	private:
		string vin;
		string licensePlate;

	public:
		Car(string, string);

	friend bool operator==(const Car&, const Car&);
	friend ostream& operator<<(ostream&, const Car&);
	friend class Hash;
};

Car::Car(string vin, string licensePlate) {
	this->vin = vin;
	this->licensePlate = licensePlate;
}

ostream& operator<<(ostream& os, const Car& car) {
	return os << "Auto con n. di telaio " << car.vin << " e targa " << car.licensePlate;
}

/* due auto sono uguali se e solo se hanno lo stesso numero di telaio e la stessa targa, ossia se sono la stessa auto */

bool operator==(const Car &one, const Car &two) {
	return one.vin == two.vin && one.licensePlate == two.licensePlate;
}

/* il nuovo operatore () restituisce l'hash del V.I.N. e del numero di targa */

struct Hash {
	size_t operator()(const Car &car) const {
		const int prime = 31;
		int result = 1;
		/* calcola l'hash di targa e numero di telaio, e li combina in un unico hash */
		size_t hashVin = hash<string>()(car.vin);
		size_t hashLPlate = hash<string>()(car.vin);
		size_t propertyHash = hashVin ^ (hashLPlate << 2);
		/* moltiplica l'hash per una costante prima, per migliorare le prestazioni */
		result = prime * result + propertyHash;
		return result;
	}
};

int main()
{
	/* crea tre nuove auto */

	Car car1("TRUVD38J891523708", "TZA 6200");
	Car car2("WVWEU73C56P566194", "LJD-5223");
	Car car3("5TBBV541X8S815592", "95266 XK");

	/* verifica l'uguaglianza tra automobili */

	Car car1copy("TRUVD38J891523708", "TZA 6200");

	cout << "L'auto originale è uguale alla sua copia? " << boolalpha << (car1 == car1copy) << endl;

	/* crea tre piloti */

	string driver1 = "Tazio Nuvolari";
	string driver2 = "Alberto Ascari";
	string driver3 = "Juan Manuel Fangio";

	unordered_map<Car, string, Hash> map;

	map.insert(std::make_pair(car1, driver1));
	map.insert(std::make_pair(car2, driver2));
	map.insert(std::make_pair(car3, driver3));

	for (auto const& it1 : map) {
		cout << it1.first << ", pilota: " << it1.second << endl;
	}

	/* recupera il pilota associato all'auto */

	auto it = map.find(car1);

	if (it != map.end()) {
		cout << "Trovata " << car1 << ", il suo pilota è: " << it->second << endl;
	}
	else {
		cout << "Automobile non trovata!" << endl;
	}
}

