/* file esercizio27.cpp */

#include <iostream>
#include <sqlite3.h>

using std::string;
using std::cerr;
using std::cout;
using std::endl;

int main()
{
	sqlite3 *db;
	sqlite3_open("bank.db", &db);

	// tabella dei conti deposito che si appoggiano ai conti correnti.

	string trns = "BEGIN TRANSACTION;";
	trns += "PRAGMA foreign_keys = ON;";
	trns += "CREATE TABLE deposit (cc VARCHAR, bal REAL, FOREIGN KEY(cc) REFERENCES customers(n_acc));";
	trns += "COMMIT;";

	// esegue la transazione
	int rc = sqlite3_exec(db, trns.c_str(), NULL, NULL, NULL);

	if (rc != SQLITE_OK) {
		cout << sqlite3_errmsg(db) << endl;
	}
	else {
		cerr << "Creata tabella dei depositi." << endl;
	}

	sqlite3_close(db);
}

