/* file esercizio18.cpp */

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::ostream_iterator;
using std::vector;
using std::sort;

class Employee {
	private:
		string matr;
		string name;
		string surname;

	public:
		Employee(string, string, string);
		string getMatr() const;
		void setMatr(string matr);
		string getName() const;
		void setName(string name);
		string getSurname() const;
		void setSurname(string surname);

	friend std::ostream& operator<<(std::ostream&, const Employee&);
};

Employee::Employee(string matr, string name, string surname) {
	this->setMatr(matr);
	this->setName(name);
	this->setSurname(surname);
}

string Employee::getMatr() const {
	return this->matr;
}

void Employee::setMatr(string matr) {
	this->matr = matr;
}

string Employee::getName() const {
	return this->name;
}

void Employee::setName(string name) {
	this->name = name;
}

string Employee::getSurname() const {
	return this->surname;
}

void Employee::setSurname(string surname) {
	this->surname = surname;
}

std::ostream& operator<<(std::ostream& os, const Employee& e) {
	os << e.matr << ", " << e.name << " " << e.surname;
	return os;
}

bool comp1(const Employee& e1, const Employee& e2) {
	return e1.getMatr() < e2.getMatr();
}

bool comp2(const Employee& e1, const Employee& e2) {
	return e1.getSurname() < e2.getSurname();
}

bool comp3(const Employee& e1, const Employee& e2) {
	bool c = e1.getName() < e2.getName();
	return c == true ? c : e1.getSurname() < e2.getSurname();
}

int main() {
	vector<Employee> ibm;

	ibm.push_back(Employee("0010", "John", "Von Neumann"));
	ibm.push_back(Employee("0011", "Gene", "Amdahl"));
	ibm.push_back(Employee("0001", "Thomas", "Watson"));
	ibm.push_back(Employee("0101", "Bob", "Bemer"));
	ibm.push_back(Employee("0100", "John", "Backus"));

	cout << "Lista originale:" << endl;

	cout << "[";
	copy(ibm.begin(), ibm.end(), ostream_iterator<Employee>(cout, ", "));
	cout << "\b\b]" << endl;

	cout << "Ordinata per matricola:" << endl;

	sort(ibm.begin(), ibm.end(), comp1);

	cout << "[";
	copy(ibm.begin(), ibm.end(), ostream_iterator<Employee>(cout, ", "));
	cout << "\b\b]" << endl;

	cout << "Ordinata per cognome:" << endl;

	sort(ibm.begin(), ibm.end(), comp2);

	cout << "[";
	copy(ibm.begin(), ibm.end(), ostream_iterator<Employee>(cout, ", "));
	cout << "\b\b]" << endl;

	cout << "Ordinata per nome e per cognome:" << endl;

	sort(ibm.begin(), ibm.end(), comp3);

	cout << "[";
	copy(ibm.begin(), ibm.end(), ostream_iterator<Employee>(cout, ", "));
	cout << "\b\b]" << endl;
}

