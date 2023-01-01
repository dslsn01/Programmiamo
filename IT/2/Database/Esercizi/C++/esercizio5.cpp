/* file esercizio5.cpp */

#include <iostream>
#include <sqlite3.h>

using std::cout;
using std::endl;

int main()
{
	sqlite3 *db;
	sqlite3_open("students.db", &db);

	int rc = sqlite3_exec(db, "DROP TABLE students", NULL, NULL, NULL);

	if (rc != SQLITE_ERROR) {
		cout << "Tabella degli studenti eliminata." << endl;
	}
	else {
		cout << sqlite3_errmsg(db) << endl;
	}

	sqlite3_close(db);
}

