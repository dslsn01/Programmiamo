/* file esercizio13.cpp */

#include <iostream>
#include <sqlite3.h>

using std::cout;
using std::endl;

int main()
{
	sqlite3 *db;
	sqlite3_stmt *res;

	sqlite3_open("students.db", &db);
	int rc = sqlite3_prepare_v2(db, "SELECT AVG(grade) FROM students", -1, &res, NULL);

	int avg = 0;

	if (rc != SQLITE_ERROR) {
		if (sqlite3_step(res) == SQLITE_ROW) {
			avg = sqlite3_column_double(res, 0);
		}

		if (!avg) {
			cout << "Nessuno studente ha ancora passato l'esame." << endl;
			sqlite3_finalize(res);
			sqlite3_close(db);
			return 0;
		}

		cout << "Voto medio: " << avg << endl;
	}
	else {
		cout << sqlite3_errmsg(db) << endl;
	}

	sqlite3_finalize(res);
	sqlite3_close(db);
}

