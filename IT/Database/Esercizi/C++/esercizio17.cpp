/*
file esercizio17.cpp
compilare con: g++ -std=c++11 esercizio17.cpp
*/

#include <iostream>
#include <stdexcept>
#include <sqlite3.h>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::invalid_argument;

int main()
{
	sqlite3 *db;
	sqlite3_stmt *pStmt;
	sqlite3_open("videostore.db", &db);

	sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS movies (id INTEGER PRIMARY KEY, title VARCHAR UNIQUE NOT NULL, year INTEGER, CHECK(LENGTH(title) <= 255), CHECK(LENGTH(year) == 4))", NULL, NULL, NULL);

	int rc = sqlite3_prepare_v2(db, "INSERT INTO movies (title, year) VALUES (?, ?)", -1, &pStmt, NULL);

	if (rc != SQLITE_ERROR) {
		cout << "Film da salvare (stringa vuota per uscire)." << endl;

		while (true) {
			cout << "Titolo film: ";

			string title;
			getline(cin, title);

			if (title.empty()) break;

			cout << "Anno: ";
			string s;
			getline(cin, s);

			int yr = 0;

			try {
				if (!s.empty()) yr = stoi(s);
			}
			catch (invalid_argument& e) {
				cout << e.what() << endl;
			}

			sqlite3_bind_text(pStmt, 1, title.c_str(), -1, SQLITE_STATIC);

			if (yr != 0) {
				sqlite3_bind_int(pStmt, 2, yr);
			}
			else {
				sqlite3_bind_null(pStmt, 2);
			}

			if (sqlite3_step(pStmt) != SQLITE_DONE) {
				cout << sqlite3_errmsg(db) << endl;
			}

			sqlite3_reset(pStmt);
			sqlite3_clear_bindings(pStmt);
		}

		sqlite3_finalize(pStmt);
		int records = sqlite3_total_changes(db);
		cout << "Registrati " << records << " film." << endl;
	}
	else {
		cout << sqlite3_errmsg(db) << endl;
	}

	sqlite3_close(db);
}

