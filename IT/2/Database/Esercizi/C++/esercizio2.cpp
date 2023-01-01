/* file esercizio2.cpp */

#include <iostream>
#include <sqlite3.h>

using std::cout;
using std::endl;

int main()
{
	sqlite3 *db;
	sqlite3_stmt *pStmt;
	sqlite3_open("students.db", &db);

	int rc = sqlite3_prepare_v2(db, "SELECT COUNT(*) FROM students", -1, &pStmt, NULL);

	if (rc == SQLITE_ERROR) {
		cout << sqlite3_errmsg(db) << endl;
		sqlite3_finalize(pStmt);
		sqlite3_close(db);
		return -1;
	}

	sqlite3_step(pStmt);
	int count = sqlite3_column_int(pStmt, 0);
	sqlite3_finalize(pStmt);

	if (count) {
		cout << "Tabella studenti non vuota!" << endl;
		sqlite3_close(db);
		return 0;
	}

	int r1 = sqlite3_exec(db, "INSERT INTO students (number, name, surname, age) VALUES ('A23234', 'Mario', 'Rossi', 19)", NULL, NULL, NULL);
	int r2 = sqlite3_exec(db, "INSERT INTO students (number, name, surname, age) VALUES ('A01357', 'Luigi', 'Bianchi', 20)", NULL, NULL, NULL);
	int r3 = sqlite3_exec(db, "INSERT INTO students (number, name, surname, age) VALUES ('A12579', 'Giovanni', 'Verdi', 20)", NULL, NULL, NULL);

	if (r1 == SQLITE_ERROR || r2 == SQLITE_ERROR || r3 == SQLITE_ERROR) {
		cout << sqlite3_errmsg(db) << endl;
		sqlite3_close(db);
		return -1;
	}

	cout << "Tre nuovi studenti iscritti al corso di programmazione." << endl;
	sqlite3_close(db);
}

