/* file esercizio7.cpp */

#include <iostream>
#include <sqlite3.h>

using std::cout;
using std::endl;

int main()
{
	sqlite3 *db;
	sqlite3_open("students.db", &db);

	int rc = sqlite3_exec(db, "ALTER TABLE students ADD COLUMN grade INTEGER", NULL, NULL, NULL);

	if (rc != SQLITE_ERROR) {
		cout << "Modificato database studenti del corso di programmazione." << endl;
	}
	else {
		cout << sqlite3_errmsg(db) << endl;
	}

	sqlite3_close(db);
}

