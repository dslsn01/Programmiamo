/*
file calc.cpp
compilare con: g++ -std=c++11 calc.cpp
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
	// legge due numeri da tastiera

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

	// converte gli operandi in numeri

	int n1 = stoi(o1);
	int n2 = stoi(o2);

	// legge l'operazione scelta

	cout << "Scegli un'operazione:\n+ - somma,\n- - sottrazione,\n* - prodotto,\n/ - divisione" << endl;

	string op;
	getline(cin, op);

	int result = 0;

	// esegue la somma

	if (op == "+") {
		result = n1 + n2;
		cout << n1 << " + " << n2 << " = " << result << endl;
	}

	// esegue la sottrazione

	if (op == "-") {
		result = n1 - n2;
		cout << n1 << " - " << n2 << " = " << result << endl;
	}

	// esegue la moltiplicazione

	if (op == "*") {
		result = n1 * n2;
		cout << n1 << " * " << n2 << " = " << result << endl;
	}

	// esegue la divisione

	if (op == "/") {
		if (n2 == 0) {
			cout << "Impossibile eseguire la divisione per zero!" << endl;
		}
		else
		{
			// stampa tre cifre decimali al massimo
			double q = (double) n1 / n2;
			cout << n1 << " / " << n2 << " = " << setprecision(4) << q << endl;
		}
	}
}

