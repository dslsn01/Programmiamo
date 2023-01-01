/* file esercizio25.cpp */

#include <iostream>
#include <sqlite3.h>

using std::string;
using std::cout;
using std::endl;

int main()
{
	sqlite3 *db;
	sqlite3_open("bank.db", &db);

	/*
	tabella clienti: codice utente e password (almeno 8 cifre), numero conto (12 cifre), iban (27 cifre in italia) e saldo conto
	tabella movimenti: codice IBAN ordinante, IBAN beneficiario, importo, casuale/descrizione, data valuta, data operativa.
	*/

	string trns = "BEGIN TRANSACTION;";
	trns += "PRAGMA foreign_keys = ON;";
	trns += "CREATE TABLE customers (n_acc VARCHAR PRIMARY KEY, iban VARCHAR UNIQUE NOT NULL, ucode INTEGER NOT NULL, password VARCHAR NOT NULL, ident VARCHAR, bal REAL, CHECK(LENGTH(n_acc) == 12), CHECK(LENGTH(ucode) == 8), CHECK(LENGTH(password) == 8), CHECK(LENGTH(iban) == 27));";
	// ord iban ordinante, ben iban beneficiario
	trns += "CREATE TABLE mov (id INTEGER PRIMARY KEY, ord VARCHAR, ben VARCHAR, imp REAL, desc VARCHAR, v_date DATE, o_date DATE, FOREIGN KEY(ord) REFERENCES customers(iban), FOREIGN KEY(ben) REFERENCES customers(iban));";
	trns += "COMMIT;";

	// esegue la transazione
	int rc = sqlite3_exec(db, trns.c_str(), NULL, NULL, NULL);

	if (rc != SQLITE_OK) {
		cout << sqlite3_errmsg(db) << endl;
		sqlite3_close(db);
		return -1;
	}

	cout << "Create le tabelle di clienti e movimenti." << endl;

	// inserisce tre clienti di prova
	sqlite3_exec(db, "INSERT INTO customers (n_acc, iban, ucode, password, ident, bal) VALUES ('000009753468', 'IT02S0300203280881249519873', 75310246, 'foobarba', 'Mario Rossi', 1000);", NULL, NULL, NULL);
	sqlite3_exec(db, "INSERT INTO customers (n_acc, iban, ucode, password, ident, bal) VALUES ('000007986541', 'IT96W0300203280997548569793', 21304152, 'barbazfo', 'Luigi Bianchi', 1500);", NULL, NULL, NULL);
	sqlite3_exec(db, "INSERT INTO customers (n_acc, iban, ucode, password, ident, bal) VALUES ('000001753429', 'IT80H0300203280392486464466', 30415263, 'bazfooba', 'Giovanni Verdi', 2500);", NULL, NULL, NULL);
	sqlite3_exec(db, "INSERT INTO customers (n_acc, iban, ucode, password, ident, bal) VALUES ('000009078653', 'IT97E0300203280833549251697', 16180339, '1,7O9975', 'Fondo di investimento', 10000000);", NULL, NULL, NULL);

	cout << "La banca ha quattro nuovi clienti!" << endl;

	sqlite3_close(db);
}

