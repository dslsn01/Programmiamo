/* file esercizio11.cpp */

#include <iostream>
#include <sqlite3.h>

using std::cout;
using std::endl;

int main()
{
	sqlite3 *db;
	sqlite3_stmt *res;

	sqlite3_open("students.db", &db);
	int rc = sqlite3_prepare_v2(db, "SELECT MAX(grade) FROM students", -1, &res, NULL);

	int max = 0;

	if (rc != SQLITE_ERROR) {
		if (sqlite3_step(res) == SQLITE_ROW) {
			max = sqlite3_column_int(res, 0);
		}

		if (!max) {
			cout << "Nessuno studente ha ancora passato l'esame." << endl;
			sqlite3_finalize(res);
			sqlite3_close(db);
			return 0;
		}

		cout << "Voto massimo: " << max << endl;
	}
	else {
		cout << sqlite3_errmsg(db) << endl;
	}

	sqlite3_finalize(res);
	sqlite3_close(db);
}

