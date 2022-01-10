/* file esercizio.cpp */

#include <iostream>
#include <sstream>
#include <sqlite3.h>

using std::string;
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	sqlite3 *db;
	sqlite3_stmt *pStmt;
	sqlite3_open("users.db", &db);

	sqlite3_prepare_v2(db, "CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, username VARCHAR UNIQUE NOT NULL, password VARCHAR NOT NULL, name VARCHAR NOT NULL, surname VARCHAR NOT NULL, CHECK(LENGTH(username) <= 50), CHECK(LENGTH(password) <= 50))", -1, &pStmt, NULL);
	sqlite3_step(pStmt);
	sqlite3_finalize(pStmt);

	// nome
	string name;

	cout << "##################################" << endl;
	cout << "####### Schermata di login #######" << endl;
	cout << "##################################" << endl;

	cout << "Username: ";
	string username;
	getline(cin, username);

	int rc = sqlite3_prepare_v2(db, "SELECT name, surname, password FROM users WHERE username = ?", -1, &pStmt, NULL);

	if (rc != SQLITE_ERROR) {
		if (!username.empty()) {
			sqlite3_bind_text(pStmt, 1, username.c_str(), -1, SQLITE_STATIC);
		}
		else {
			sqlite3_bind_null(pStmt, 1);
		}

		if (sqlite3_step(pStmt) == SQLITE_DONE) {
			sqlite3_finalize(pStmt);

			cout << "Username \"" << username << "\" non presente! Vuoi registrarti? s | n: ";
			string opt;
			getline(cin, opt); // .toLowerCase();

			if (!(opt == "s")) return 0;

			cout << "Password: ";
			string pwd;
			getline(cin, pwd);

			cout << "Nome: ";
			getline(cin, name);

			cout << "Cognome: ";
			string surname;
			getline(cin, surname);

			sqlite3_prepare_v2(db, "INSERT INTO users (username, password, name, surname) VALUES (?, ?, ?, ?)", -1, &pStmt, NULL);

			sqlite3_bind_text(pStmt, 1, username.c_str(), -1, SQLITE_STATIC);

			if (!pwd.empty()) {
				sqlite3_bind_text(pStmt, 2, pwd.c_str(), -1, SQLITE_STATIC);
			}
			else {
				sqlite3_bind_null(pStmt, 2);
			}

			if (!name.empty()) {
				sqlite3_bind_text(pStmt, 3, name.c_str(), -1, SQLITE_STATIC);
			}
			else {
				sqlite3_bind_null(pStmt, 3);
			}

			if (!surname.empty()) {
				sqlite3_bind_text(pStmt, 4, surname.c_str(), -1, SQLITE_STATIC);
			}
			else {
				sqlite3_bind_null(pStmt, 4);
			}

			if (sqlite3_step(pStmt) != SQLITE_DONE) {
				cerr << sqlite3_errmsg(db) << endl;
			}

			sqlite3_finalize(pStmt);
		}
		else {
			// nome
			name = (const char*) sqlite3_column_text(pStmt, 0);
			string p = (const char*) sqlite3_column_text(pStmt, 2);

			sqlite3_finalize(pStmt);

			bool auth = false;
			int i = 0; // numero tentativi di autenticazione

			while (!auth) {
				cout << "Password: ";
				string pwd;
				getline(cin, pwd);

				if (pwd != p) {
					i++;
					cerr << "Password non corretta!" << endl;
					if (i < 3) continue;
					else {
						cerr << "Tre tentativi di autenticazione fallita: stop." << endl;
						return -1;
					}
				}

				auth = true;
			}
		}

		cout << "++++++++++++++++++++++++++++++++++" << endl;
		cout << "Benvenuto, " << name << "!" << endl;
	}
	else {
		cerr << sqlite3_errmsg(db) << endl;
	}

	sqlite3_close(db);
}

