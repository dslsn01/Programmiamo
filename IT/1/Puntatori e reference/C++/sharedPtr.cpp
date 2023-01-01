/*
file sharedPtr.cpp
compilare con: g++ -std=c++11 sharedPtr.cpp
*/

#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;
using std::make_shared;

struct Employee {
	int matr;
	string name;
	double salary;

	~Employee() {
		cout << "L'impiegato non serve più. Libero la memoria." << endl;
	}
};

void f1(shared_ptr<Employee> ptr, string s) {
	ptr->name = s;
}

void f2(shared_ptr<Employee> ptr, double v) {
	ptr->salary = v;
}

int main()
{
	/* il main() è il primo owner del puntatore */

	cout << "Nel main() viene creato un nuovo impiegato." << endl;

	shared_ptr<Employee> ptr = make_shared<Employee>();
	ptr->matr = 1010101;

	cout << "Matricola: " << ptr->matr << endl;

	/* la funzione f1() è il secondo owner del puntatore */

	f1(ptr, "John Doe");

	cout << "Matricola: " << ptr->matr << ", nome: " << ptr->name << endl;

	/* la funzione f2() è il terzo owner del puntatore */

	f2(ptr, 39000.0);

	cout << "Matricola: " << ptr->matr << ", nome: " << ptr->name << ", salario: " << ptr->salary << " euro." << endl;
}

