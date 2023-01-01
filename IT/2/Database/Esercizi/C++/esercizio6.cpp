/* file esercizio6.cpp */

#include <iostream>
#include <sqlite3.h>

using std::cout;
using std::endl;

int main()
{
	sqlite3 *db;
	sqlite3_open("students.db", &db);

	int rc = sqlite3_exec(db, "CREATE TABLE students (id INTEGER PRIMARY KEY, number VARCHAR UNIQUE NOT NULL, name VARCHAR NOT NULL, surname VARCHAR NOT NULL, age INTEGER, CHECK(LENGTH(number) == 6), CHECK(LENGTH(name) <= 255), CHECK(LENGTH(surname) <= 255))", NULL, NULL, NULL);

	if (rc != SQLITE_ERROR) {
		cout << "Creato database studenti del corso di programmazione." << endl;
	}
	else {
		cout << sqlite3_errmsg(db) << endl;
	}

	sqlite3_close(db);
}

