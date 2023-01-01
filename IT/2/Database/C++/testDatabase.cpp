/*
file testDatabase.cpp
compilare con: g++ testDatabase.cpp -lsqlite3
*/

#include <iostream>
#include <sqlite3.h>

using std::cout;
using std::endl;

int main()
{
	/* connessione al database */

	sqlite3 *db;

	/* prepared statement per interagire con il database */

	sqlite3_stmt *result;

	/* apre la connessione */

	sqlite3_open("test.db", &db);

	/* crea la nuova tabella degli scrittori */

	sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS writers (id INTEGER PRIMARY KEY, name VARCHAR NOT NULL, surname VARCHAR NOT NULL, CHECK(LENGTH(name) <= 256), CHECK(LENGTH(surname) <= 256))", NULL, NULL, NULL);

	/* svuota la tabella creata in precedenza: solo a scopo d'esempio! */

	sqlite3_exec(db, "DELETE FROM writers", NULL, NULL, NULL);

	/* aggiunge tre righe alla tabella degli scrittori */

	sqlite3_exec(db, "INSERT INTO writers (name, surname) VALUES ('Robert', 'Howard')", NULL, NULL, NULL);
	sqlite3_exec(db, "INSERT INTO writers (name, surname) VALUES ('Philip K.', 'Dick')", NULL, NULL, NULL);
	sqlite3_exec(db, "INSERT INTO writers (name, surname) VALUES ('Isaac', 'Asimov')", NULL, NULL, NULL);

	/* seleziona tutti gli scrittori */

	sqlite3_prepare_v2(db, "SELECT * FROM writers", -1, &result, NULL);

	/* finchè ci sono righe da stampare, stampa ciascuna colonna di ogni riga */

	while (sqlite3_step(result) == SQLITE_ROW) {
		cout << sqlite3_column_int(result, 0) << " " << sqlite3_column_text(result, 1) << " " << sqlite3_column_text(result, 2) << endl;
	}

	/* finalizza lo statement e chiude la connessione al database */

	sqlite3_finalize(result);
	sqlite3_close(db);
}

