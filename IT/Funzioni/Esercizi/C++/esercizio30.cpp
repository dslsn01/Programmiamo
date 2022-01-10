/* 
file esercizio30.cpp
compilare con: g++ -std=c++11 esercizio30.cpp
*/

#include <iostream>
#include <iomanip>
#include <regex>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::regex;
using std::string;

int main()
{
	// somma
	auto add = [](int n1, int n2) { return n1 + n2; };

	// sottrazione
	auto subtr = [](int n1, int n2) { return n1 - n2; };

	// prodotto
	auto mult = [](int n1, int n2) { return n1 * n2; };

	// divisione
	auto divide = [](int n1, int n2) { return n2 != 0 ? (float)n1 / n2 : NAN; };

	string o1 = "?";
	string o2 = o1;

	regex num(R"([+-]?[0-9]+)");

	while (!regex_match(o1, num)) {
		if (o1.empty()) cout << "Stringa vuota!" << endl;
		else if (o1 != "?") cout << "Numero \"" << o1 << "\" non valido!" << endl;
		cout << "Primo operando: ";
		getline(cin, o1);
	}

	while (!regex_match(o2, num)) {
		if (o2.empty()) cout << "Stringa vuota!" << endl;
		else if (o2 != "?") cout << "Numero \"" << o2 << "\" non valido!" << endl;
		cout << "Secondo operando: ";
		getline(cin, o2);
	}

	int n1 = stoi(o1);
	int n2 = stoi(o2);

	cout << "Scegli un'operazione:" << endl << "+ - somma," << endl << "- - sottrazione," << endl << "* - prodotto," << endl << "/ - divisione" << endl;

	string op;
	getline(cin, op);

	if (op == "+") {
		cout << n1 << " + " << n2 << " = " << add(n1, n2) << endl;
	}

	if (op == "-") {
		cout << n1 << " - " << n2 << " = " << subtr(n1, n2) << endl;
	}

	if (op == "*") {
		cout << n1 << " * " << n2 << " = " << mult(n1, n2) << endl;
	}

	if (op == "/") {
		cout << n1 << " / " << n2 << " = " << setprecision(4) << divide(n1, n2) << endl;
	}
}

