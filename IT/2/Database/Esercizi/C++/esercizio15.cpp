/* file esercizio15.cpp */

#include <iostream>
#include <sqlite3.h>

using std::string;
using std::cout;
using std::endl;

int main()
{
	sqlite3 *db;
	sqlite3_stmt *res;

	sqlite3_open("students.db", &db);

	string query = "SELECT a.number, a.name, a.surname, a.grade ";
	query += "FROM students a ";
	query += "INNER JOIN (";
	query += "SELECT MIN(grade) AS grade FROM students";
	query += ") b ON a.grade = b.grade";

	int rc = sqlite3_prepare_v2(db, query.c_str(), -1, &res, NULL);

	if (rc != SQLITE_ERROR) {
		if (sqlite3_step(res) == SQLITE_DONE) {
			cout << "Nessuno studente ha ancora passato l'esame." << endl;
			sqlite3_finalize(res);
			sqlite3_close(db);
			return 0;
		}

		do {
			string num = (const char*) sqlite3_column_text(res, 0);
			string name = (const char*) sqlite3_column_text(res, 1);
			string surname = (const char*) sqlite3_column_text(res, 2);
			int min = sqlite3_column_int(res, 3);
			cout << "Matricola " << num << ", " << name << " " << surname << ", voto: " << min << endl;
		} while (sqlite3_step(res) == SQLITE_ROW);
	}
	else {
		cout << sqlite3_errmsg(db) << endl;
	}

	sqlite3_finalize(res);
	sqlite3_close(db);
}

