/* file esercizio10.cpp */

#include <iostream>
#include <stdexcept>
#include <sqlite3.h>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::invalid_argument;

int main()
{
	cout << "Elimina uno o più studenti." << endl;

	sqlite3 *db;
	sqlite3_stmt *res;
	sqlite3_stmt *pStmt;
	sqlite3_open("students.db", &db);

	int rc = sqlite3_prepare_v2(db, "SELECT number, name, surname FROM students", -1, &res, NULL);

	if (rc != SQLITE_ERROR) {
		if (sqlite3_step(res) == SQLITE_DONE) {
			cout << "Non ci sono studenti iscritti al corso!" << endl;
			sqlite3_finalize(res);
			sqlite3_close(db);
			return 0;
		}

		sqlite3_prepare_v2(db, "DELETE FROM students WHERE number = ?", -1, &pStmt, NULL);

		do {
			string num = (const char*) sqlite3_column_text(res, 0);
			string name = (const char*) sqlite3_column_text(res, 1);
			string surname = (const char*) sqlite3_column_text(res, 2);
			cout << "Matricola " << num << ", " << name << " " << surname << "." << endl;
			// studente da eliminare:

			cout << "Rimuovere lo studente dal corso? ";
			string opt;
			getline(cin, opt);

			if (opt != "s") continue;

			sqlite3_bind_text(pStmt, 1, num.c_str(), -1, SQLITE_STATIC);

			if (sqlite3_step(pStmt) != SQLITE_DONE) {
				cout << sqlite3_errmsg(db) << endl;
			}

			sqlite3_reset(pStmt);
			sqlite3_clear_bindings(pStmt);

		} while (sqlite3_step(res) == SQLITE_ROW);

		int records = sqlite3_total_changes(db);
		cout << "Eliminati " << records << " nominativi di studenti." << endl;
	}
	else {
		cout << sqlite3_errmsg(db) << endl;
	}

	sqlite3_finalize(res);
	sqlite3_finalize(pStmt);
	sqlite3_close(db);
}

