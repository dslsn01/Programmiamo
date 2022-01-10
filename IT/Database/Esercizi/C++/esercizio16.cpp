/* file esercizio16.cpp */

#include <iostream>
#include <sqlite3.h>

using std::cout;
using std::endl;

int main()
{
	sqlite3 *db;
	sqlite3_stmt *pStmt;

	sqlite3_open("students.db", &db);
	int rc = sqlite3_prepare_v2(db, "DELETE FROM students WHERE grade IS NOT NULL", -1, &pStmt, NULL);

	if (rc != SQLITE_ERROR) {
		if (sqlite3_step(pStmt) == SQLITE_DONE) {
			cout << "Rimossi studenti che hanno superato l'esame." << endl;
		}
	}
	else {
		cout << sqlite3_errmsg(db) << endl;
	}

	sqlite3_finalize(pStmt);
	sqlite3_close(db);
}

