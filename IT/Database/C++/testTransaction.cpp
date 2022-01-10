/*
file testTransaction.cpp
compilare con: g++ -std=c++11 testTransaction.cpp -lsqlite3
*/

#include <iostream>
#include <sstream>
#include <time.h>
#include <sqlite3.h>
#include <iomanip>

using std::string;
using std::cout;
using std::endl;
using std::istringstream;
using std::get_time;

int main()
{
	sqlite3 *db;
	sqlite3_stmt *pStmt;
	sqlite3_open("list.db", &db);

	string trns = "BEGIN TRANSACTION;";
	trns += "PRAGMA foreign_keys = ON;";

	// crea tabella dei pazienti, lista d'attesa e degli interventi programmati

	trns += "CREATE TABLE IF NOT EXISTS patients (name VARCHAR NOT NULL, surname VARCHAR NOT NULL, PRIMARY KEY(name, surname), CHECK(LENGTH(name) <= 256), CHECK(LENGTH(surname) <= 256));";
	trns += "CREATE TABLE IF NOT EXISTS wtList (name VARCHAR, surname VARCHAR, r_date DATE NOT NULL, FOREIGN KEY(name, surname) REFERENCES patients(name, surname) ON DELETE CASCADE);";
	trns += "CREATE TABLE IF NOT EXISTS interv (name VARCHAR, surname VARCHAR, sched DATE NOT NULL, desc VARCHAR, CHECK(LENGTH(desc) <= 256), FOREIGN KEY(name, surname) REFERENCES patients(name, surname) ON DELETE CASCADE);";

	// svuota tutt'e tre le tabelle (solo a scopo di test!)
	trns += "DELETE FROM patients;";
	trns += "DELETE FROM wtList;";
	trns += "DELETE FROM interv;";

	// salva i nominativi di tre pazienti

	trns += "INSERT INTO patients (name, surname) VALUES ('Giovanni', 'Verdi');";
	trns += "INSERT INTO patients (name, surname) VALUES ('Giuseppe', 'Bianchi');";
	trns += "INSERT INTO patients (name, surname) VALUES ('Luigi', 'Rossi');";

	// inserisce due pazienti in lista d'attesa in modo casuale

	trns += "INSERT INTO wtList (name, surname, r_date) SELECT name, surname, DATE('now') FROM patients ORDER BY RANDOM() LIMIT 2;";

	trns += "COMMIT;";

	int rc = sqlite3_exec(db, trns.c_str(), NULL, NULL, NULL);

	if (rc != SQLITE_OK) {
		cout << sqlite3_errmsg(db) << endl;
		sqlite3_close(db);
		return -1;
	}

	string name;
	string surname;
	struct tm r_date = {0};

	sqlite3_prepare_v2(db, "SELECT name, surname, r_date FROM wtList LIMIT 1", -1, &pStmt, NULL);

	if (sqlite3_step(pStmt) == SQLITE_ROW) {
		name = (const char*) sqlite3_column_text(pStmt, 0);
		surname = (const char*) sqlite3_column_text(pStmt, 1);
		const char *buf = (const char*) sqlite3_column_text(pStmt, 2);

		istringstream ss(buf);
		ss >> get_time(&r_date, "%Y-%m-%d");

		char rbuf[15];
		strftime(rbuf, sizeof(rbuf), "%d/%m/%Y", &r_date);
		cout << "Il paziente " << name << " " << surname << " è in lista d'attesa dal " << rbuf << "." << endl;
	}

	sqlite3_finalize(pStmt);

	// inizio seconda transazione

	sqlite3_exec(db, "BEGIN TRANSACTION;", NULL, NULL, NULL);

	// inserisce un paziente nella lista degli interventi programmati, rimuovendolo dalla lista d'attesa

	sqlite3_prepare_v2(db, "INSERT INTO interv (name, surname, desc, sched) VALUES (?, ?, ?, ?)", -1, &pStmt, NULL);
	sqlite3_bind_text(pStmt, 1, name.c_str(), -1, SQLITE_STATIC);
	sqlite3_bind_text(pStmt, 2, surname.c_str(), -1, SQLITE_STATIC);
	sqlite3_bind_text(pStmt, 3, "endodonzia", -1, SQLITE_STATIC);

	r_date.tm_mday += 3;
	// normalizza la data
	mktime(&r_date);

	char i_date[15];
	strftime(i_date, sizeof(i_date), "%Y-%m-%d", &r_date);

	sqlite3_bind_text(pStmt, 4, i_date, -1, SQLITE_STATIC);
	sqlite3_step(pStmt);
	sqlite3_finalize(pStmt);

	sqlite3_prepare_v2(db, "DELETE FROM wtList WHERE name = ? AND surname = ?", -1, &pStmt, NULL);
	sqlite3_bind_text(pStmt, 1, name.c_str(), -1, SQLITE_STATIC);
	sqlite3_bind_text(pStmt, 2, surname.c_str(), -1, SQLITE_STATIC);
	sqlite3_step(pStmt);
	sqlite3_finalize(pStmt);

	// fine seconda transazione

	sqlite3_exec(db, "COMMIT;", NULL, NULL, NULL);

	char ibuf[15];
	strftime(ibuf, sizeof(ibuf), "%d/%m/%Y", &r_date);

	cout << name << " " << surname << " sarà sottoposto a intervento il giorno " << ibuf << "." << endl;

	sqlite3_close(db);
}

