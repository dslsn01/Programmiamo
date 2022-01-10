/*
file esercizio28.cpp
compilare con: g++ -std=c++11 esercizio28.cpp
*/

#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::string;
using std::to_string;
using std::logic_error;

class ATMAuthException : public logic_error {
	using logic_error::logic_error;
};

class ATM {
	private:
		bool login = false;
		bool run = true;
		double balance = 1500;
		void enterPin();
	public:
		ATM();
};

void ATM::enterPin() {
	if (!this->login) {
		cout << "Inserisci il P.I.N.: ";
		string pin;
		getline(cin, pin);

		if (pin == "12345") {
			this->login = true;
		}
		else {
			throw ATMAuthException("PIN non valido!");
		}
	}
}

ATM::ATM() {
	cout << "+++++++ Sportello ATM +++++++" << endl;

	while (this->run) {
		cout << endl << "Operazioni disponibili:" << endl << endl;
		cout << "1. Saldo" << endl;
		cout << "2. Prelievo" << endl;
		cout << "3. Deposito" << endl;
		cout << "4. Esci" << endl << endl;

		cout << "Scegli l'operazione (1, 2, 3, 4): ";

		string oper;
		getline(cin, oper);

		try {
			if (oper == "1") {
				this->enterPin();
				cout << endl << "---------------------" << endl;
				cout << "Saldo corrente: " << this->balance << " euro." << endl;
				cout << "---------------------" << endl;
			}
			else if (oper == "2") {
				this->enterPin();
				cout << "Importo da prelevare: ";

				string s;
				getline(cin, s);
				double cash = stod(s);

				this->balance -= cash;
				cout << endl << "---------------------" << endl;
				cout << "Hai prelevato " << cash << " euro. Saldo corrente: " << this->balance << endl;
				cout << "---------------------" << endl;
			}
			else if (oper == "3") {
				this->enterPin();
				cout << "Importo da versare: ";
				string s;
				getline(cin, s);
				double cash = stod(s);

				this->balance += cash;
				cout << endl << "---------------------" << endl;
				cout << "Hai versato " << cash << " euro. Saldo corrente: " << this->balance << endl;
				cout << "---------------------" << endl;
			}
			else if (oper == "4") {
				cout << "Grazie di avere utilizzato i nostri servizi ATM." << endl;
				this->run = false;
			}
			else {
				cout << "Operazione sconosciuta!" << endl;
			}
		}
		catch (logic_error &e) {
			cerr << endl << "xxxxxxxxxxxxxxxxxxxxx" << endl;
			cerr << e.what() << endl;
			cerr << "xxxxxxxxxxxxxxxxxxxxx" << endl;
		}
	}
}

int main() {
	ATM atm;
}

