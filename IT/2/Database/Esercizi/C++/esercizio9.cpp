/*
file esercizio9.cpp
compilare con: g++ -std=c++11 esercizio9.cpp
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
	cout << "Aggiorna il voto d'esame degli studenti." << endl;

	sqlite3 *db;
	sqlite3_stmt *res;
	sqlite3_stmt *pStmt;
	sqlite3_open("students.db", &db);

	int rc = sqlite3_prepare_v2(db, "SELECT number, name, surname FROM students", -1, &res, NULL);

	if (rc != SQLITE_ERROR) {
		if (sqlite3_step(res) == SQLITE_DONE) {
			cout << "Non ci sono studenti iscritti al corso!" << endl;
			sqlite3_finalize(res);
			sqlite3_close(db);
			return 0;
		}

		sqlite3_prepare_v2(db, "UPDATE students SET grade = ? WHERE number = ?", -1, &pStmt, NULL);

		do {
			string num = (const char*) sqlite3_column_text(res, 0);
			string name = (const char*) sqlite3_column_text(res, 1);
			string surname = (const char*) sqlite3_column_text(res, 2);
			cout << "Matricola " << num << ", " << name << " " << surname << "." << endl;

			cout << "Voto (da 18 a 30): ";
			string s;
			getline(cin, s);

			if (s.empty()) continue;

			int grade = 0;

			try {
				grade = stoi(s);
				if (grade < 18 || grade > 30) {
					cout << "Voto non valido!" << endl;
					continue;
				}
			}
			catch (invalid_argument& e) {
				cout << e.what() << endl;
				continue;
			}

			if (grade != 0) {
				sqlite3_bind_int(pStmt, 1, grade);
			}
			else {
				sqlite3_bind_null(pStmt, 1);
			}

			sqlite3_bind_text(pStmt, 2, num.c_str(), -1, SQLITE_STATIC);

			if (sqlite3_step(pStmt) != SQLITE_DONE) {
				cout << sqlite3_errmsg(db) << endl;
			}

			sqlite3_reset(pStmt);
			sqlite3_clear_bindings(pStmt);

		} while (sqlite3_step(res) == SQLITE_ROW);

		int records = sqlite3_total_changes(db);
		cout << records << " studenti hanno passato la prova d'esame." << endl;
	}
	else {
		cout << sqlite3_errmsg(db) << endl;
	}

	sqlite3_finalize(res);
	sqlite3_finalize(pStmt);
	sqlite3_close(db);
}

