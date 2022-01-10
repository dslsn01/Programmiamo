/* file esercizio1.cpp */

#include <iostream>
#include <sqlite3.h>

using std::cout;
using std::endl;

int main()
{
	sqlite3 *db;
	sqlite3_open("students.db", &db);

	int rc = sqlite3_exec(db, "CREATE TABLE students (id INTEGER PRIMARY KEY, number VARCHAR, name VARCHAR, surname VARCHAR, age INTEGER)", NULL, NULL, NULL);

	if (rc == SQLITE_ERROR) {
		cout << sqlite3_errmsg(db) << endl;
		sqlite3_close(db);
		return -1;
	}

	cout << "Creato database studenti del corso di programmazione." << endl;
	sqlite3_close(db);
}

