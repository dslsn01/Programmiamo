/* file esercizio4.cpp */

#include <iostream>
#include <sqlite3.h>

using std::cout;
using std::endl;

int main()
{
	sqlite3 *db;
	sqlite3_open("students.db", &db);

	int rc = sqlite3_exec(db, "DELETE FROM students", NULL, NULL, NULL);

	if (rc != SQLITE_ERROR) {
		cout << "Tabella degli studenti svuotata." << endl;
	}
	else {
		cout << sqlite3_errmsg(db) << endl;
	}

	sqlite3_close(db);
}

