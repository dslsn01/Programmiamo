/* file esercizio3.cpp */

#include <iostream>
#include <sqlite3.h>

using std::string;
using std::cout;
using std::endl;

int main()
{
	sqlite3 *db;
	sqlite3_stmt *res;
	sqlite3_open("students.db", &db);

	int rc = sqlite3_prepare_v2(db, "SELECT number, name, surname FROM students", -1, &res, NULL);

	if (rc != SQLITE_ERROR) {
		if (sqlite3_step(res) == SQLITE_DONE) {
			cout << "Non ci sono studenti iscritti al corso!" << endl;
			sqlite3_finalize(res);
			sqlite3_close(db);
			return 0;
		}

		do {
			string number = (const char*) sqlite3_column_text(res, 0);
			string name = (const char*) sqlite3_column_text(res, 1);
			string surname = (const char*) sqlite3_column_text(res, 2);
			cout << "Matricola " << number << ", " << name << " " << surname << "." << endl;
		}
		while (sqlite3_step(res) == SQLITE_ROW);
	}
	else {
		cout << sqlite3_errmsg(db) << endl;
	}

	sqlite3_finalize(res);
	sqlite3_close(db);
}

