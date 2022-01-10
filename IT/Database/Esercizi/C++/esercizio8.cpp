/*
file esercizio8.cpp
compilare con: g++ -std=c++11 esercizio8.cpp
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
	cout << "Inserisci gli studenti del corso (matricola vuota per uscire)." << endl;

	sqlite3 *db;
	sqlite3_stmt *pStatement;
	sqlite3_open("students.db", &db);

	int rc = sqlite3_prepare_v2(db, "INSERT INTO students (number, name, surname, age, grade) VALUES (?, ?, ?, ?, ?)", -1, &pStatement, NULL);

	if (rc != SQLITE_ERROR) {
		while (true) {
			cout << "Numero di matricola: ";
			string num;
			getline(cin, num);

			if (num.empty()) break;

			cout << "Nome: ";
			string name;
			getline(cin, name);

			cout << "Cognome: ";
			string surname;
			getline(cin, surname);

			int age = 0;
			int grade = 0;

			try {
				string s1;
				cout << "Anni: ";
				getline(cin, s1);
				age = stoi(s1);

				string s2;
				cout << "Voto d'esame: ";
				getline(cin, s2);
				int tmp = stoi(s2);

				if (tmp >= 18 || tmp <= 30) grade = tmp;
				else cout << "Voto non valido!" << endl;
			}
			catch (invalid_argument& e) {
				cout << e.what() << endl;
			}

			if (!num.empty()) {
				sqlite3_bind_text(pStatement, 1, num.c_str(), -1, SQLITE_STATIC);
			}
			else {
				sqlite3_bind_null(pStatement, 1);
			}

			if (!name.empty()) {
				sqlite3_bind_text(pStatement, 2, name.c_str(), -1, SQLITE_STATIC);
			}
			else {
				sqlite3_bind_null(pStatement, 2);
			}

			if (!surname.empty()) {
				sqlite3_bind_text(pStatement, 3, surname.c_str(), -1, SQLITE_STATIC);
			}
			else {
				sqlite3_bind_null(pStatement, 3);
			}

			if (age != 0) {
				sqlite3_bind_int(pStatement, 4, age);
			}
			else {
				sqlite3_bind_null(pStatement, 4);
			}

			if (grade != 0) {
				sqlite3_bind_int(pStatement, 5, grade);
			}
			else {
				sqlite3_bind_null(pStatement, 5);
			}

			if (sqlite3_step(pStatement) != SQLITE_DONE) {
				cout << sqlite3_errmsg(db) << endl;
			}

			sqlite3_reset(pStatement);
			sqlite3_clear_bindings(pStatement);
		}

		int records = sqlite3_total_changes(db);
		cout << "Registrati " << records << " studenti." << endl;
	}
	else {
		cout << sqlite3_errmsg(db) << endl;
	}

	sqlite3_finalize(pStatement);
	sqlite3_close(db);
}

