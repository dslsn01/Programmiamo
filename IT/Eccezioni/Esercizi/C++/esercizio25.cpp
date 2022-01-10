/*
file esercizio25.cpp
compilare con: g++ -std=c++11 esercizio25.cpp
*/

#include <iostream>
#include <array>
#include <stdexcept>

using std::cout;
using std::endl;
using std::cerr;
using std::string;
using std::to_string;
using std::ostream;
using std::logic_error;

class MyDate {
	private:
		int yyyy;
		int mm;
		int dd;

	public:
		MyDate(int, int, int);
		int getDD();
		int getMM();
		int getYYYY();
		void setDD(int);
		void setMM(int);
		void setYYYY(int);

	friend ostream& operator<<(ostream&, const MyDate&);
};

MyDate::MyDate(int dd, int mm, int yyyy) {
	try {
		this->setYYYY(yyyy);
		this->setMM(mm);
		this->setDD(dd);
	}
	catch (logic_error& e) {
		cerr << e.what() << endl;
		this->setYYYY(1970);
		this->setMM(1);
		this->setDD(1);
	}
}

int MyDate::getDD() {
	return this->dd;
}

void MyDate::setDD(int dd) {
	if (dd < 1) {
		throw logic_error("Giorno (" + to_string(dd) + ") non valido!");
	}

	int minDD = 1;
	int maxDD = 0;

	if (this->mm == 4 || this->mm == 6 || this->mm == 9 || this->mm == 11) {
		maxDD = 30;
	}
	else if (this->mm == 2) {
		maxDD = 28;
	}
	else {
		maxDD = 31;
	}

	if (dd > maxDD) {
		throw logic_error("Giorno (" + to_string(dd) + ") non valido!");
	}

	this->dd = dd;
}

int MyDate::getMM() {
	return this->mm;
}

void MyDate::setMM(int mm) {
	if (mm < 1 || mm > 12) {
		throw logic_error("Mese (" + to_string(mm) + ") non valido!");
	}
	this->mm = mm;
}

int MyDate::getYYYY() {
	return this->yyyy;
}

void MyDate::setYYYY(int yyyy) {
	if (yyyy <= 0) {
		throw logic_error("Anno (" + to_string(yyyy) + ") non valido!");
	}
	this->yyyy = yyyy;
}

ostream& operator<<(ostream& os, const MyDate& d) {
	return os << d.dd << "-" << d.mm << "-" << d.yyyy;
}

int main()
{
	MyDate d(1, 1, 2000);
	cout << d << endl;

	d = MyDate(1, 13, 2000);
	cout << d << endl;
}

