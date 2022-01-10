/* file esercizio.cpp */

#include <iostream>
#include <ctime>
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

	sqlite3_prepare_v2(db, "CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, username VARCHAR UNIQUE NOT NULL, password VARCHAR NOT NULL, name VARCHAR NOT NULL, surname VARCHAR NOT NULL, r_date TIMESTAMP, llogin TIMESTAMP, CHECK(LENGTH(username) <= 50), CHECK(LENGTH(password) <= 50))", -1, &pStmt, NULL);
	sqlite3_step(pStmt);
	sqlite3_finalize(pStmt);

	// nome, data di registrazione e ultimo login
	string name;
	string r_date;
	string llogin;

	cout << "##################################" << endl;
	cout << "####### Schermata di login #######" << endl;
	cout << "##################################" << endl;

	cout << "Username: ";
	string username;
	getline(cin, username);

	int rc = sqlite3_prepare_v2(db, "SELECT name, surname, password, r_date, llogin FROM users WHERE username = ?", -1, &pStmt, NULL);

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

			sqlite3_prepare_v2(db, "INSERT INTO users (username, password, name, surname, r_date, llogin) VALUES (?, ?, ?, ?, ?, ?)", -1, &pStmt, NULL);

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

			time_t now = time(NULL);
			struct tm *timeinfo = localtime(&now);
			char rbuf[15];
			strftime(rbuf, sizeof(rbuf), "%Y-%m-%d", timeinfo);

			sqlite3_bind_text(pStmt, 5, rbuf, -1, SQLITE_STATIC);

			char lbuf[25];
			strftime(lbuf, sizeof(lbuf), "%Y-%m-%d %H:%M:%S", timeinfo);

			sqlite3_bind_text(pStmt, 6, lbuf, -1, SQLITE_STATIC);

			// registrazione e ultimo login vengono visualizzate in formati diversi
			char dt[15];
			strftime(dt, sizeof(dt), "%d/%m/%Y", timeinfo);
			r_date = dt;

			char ll[25];
			strftime(ll, sizeof(ll), "%d/%m/%Y %H:%M:%S", timeinfo);
			llogin = ll;

			if (sqlite3_step(pStmt) != SQLITE_DONE) {
				cerr << sqlite3_errmsg(db) << endl;
			}

			sqlite3_finalize(pStmt);
		}
		else {
			name = (const char*) sqlite3_column_text(pStmt, 0);
			string p = (const char*) sqlite3_column_text(pStmt, 2);
			const char *rbuf = (const char*) sqlite3_column_text(pStmt, 3);

			struct tm timeinfo;
			strptime(rbuf, "%Y-%m-%d", &timeinfo);

			char dt[15];
			strftime(dt, sizeof(dt), "%d/%m/%Y", &timeinfo);
			r_date = dt;

			// data ultimo accesso
			const char *lbuf = (const char*) sqlite3_column_text(pStmt, 4);
			// TODO: gestisci il caso che sia NULL
			if (lbuf != NULL) {
				strptime(lbuf, "%Y-%m-%d %H:%M:%S", &timeinfo);
				char ll[25];
				strftime(ll, sizeof(ll), "%d/%m/%Y %H:%M:%S", &timeinfo);
				llogin = ll;
			}
			else llogin = r_date;

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

			sqlite3_prepare_v2(db, "UPDATE users SET llogin = ? WHERE username = ?", -1, &pStmt, NULL);
			time_t now = time(NULL);
			struct tm *t_now = localtime(&now);

			char date[25];
			strftime(date, sizeof(date), "%Y-%m-%d %H:%M:%S", t_now);

			sqlite3_bind_text(pStmt, 1, date, -1, SQLITE_STATIC);
			sqlite3_bind_text(pStmt, 2, username.c_str(), -1, SQLITE_STATIC);
			sqlite3_step(pStmt);
			sqlite3_finalize(pStmt);
		}

		cout << "++++++++++++++++++++++++++++++++++" << endl;
		cout << "Benvenuto, " << name << "!" << endl << "Sei registrato dal " << r_date << "." << endl << "Ultimo accesso effettuato il " << llogin << "." << endl;
	}
	else {
		cerr << sqlite3_errmsg(db) << endl;
	}

	sqlite3_close(db);
}

