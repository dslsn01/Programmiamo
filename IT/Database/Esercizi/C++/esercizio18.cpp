/* file esercizio18.cpp */

#include <iostream>
#include <sqlite3.h>

using std::cout;
using std::endl;

int main()
{
	sqlite3 *db;
	sqlite3_stmt *res;
	sqlite3_open("videostore.db", &db);

	int rc = sqlite3_prepare_v2(db, "SELECT title, year FROM movies", -1, &res, NULL);

	if (rc != SQLITE_ERROR) {
		if (sqlite3_step(res) == SQLITE_DONE) {
			cout << "Nessun film disponibile in videoteca!" << endl;
			sqlite3_finalize(res);
			sqlite3_close(db);
			return 0;
		}

		do {
			cout << (const char*) sqlite3_column_text(res, 0);
			int yr = sqlite3_column_int(res, 1);
			if (yr != 0) cout << " (" << yr << ")";
			cout << "." << endl;
		}
		while (sqlite3_step(res) == SQLITE_ROW);
	}
	else {
		cout << sqlite3_errmsg(db) << endl;
	}

	sqlite3_finalize(res);
	sqlite3_close(db);
}

