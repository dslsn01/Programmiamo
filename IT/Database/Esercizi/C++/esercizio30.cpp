/*
file esercizio30.cpp
compilare con: g++ -std=c++11 esercizio30.cpp
*/

#include <iostream>
#include <ctime>
#include <stdexcept>
#include <sqlite3.h>

using std::string;
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::invalid_argument;

bool listOrd(sqlite3 *db, string username) {
	bool rc = false;
	sqlite3_stmt *pStmt;
	sqlite3_prepare_v2(db, "SELECT o.id, o.product, p.price FROM orders o, products p WHERE user = ? AND o.product = p.name AND o.paid = 0", -1, &pStmt, NULL);
	sqlite3_bind_text(pStmt, 1, username.c_str(), -1, SQLITE_STATIC);

	if (sqlite3_step(pStmt) == SQLITE_DONE) {
		cout << "[X] Nessun ordine presente." << endl;
	}
	else {
		rc = true;
		do {
			int id = sqlite3_column_int(pStmt, 0);
			string p = (const char*) sqlite3_column_text(pStmt, 1);
			double pr = sqlite3_column_double(pStmt, 2);
			cout << "[" << id << "] " << p << " - " << pr << " euro." << endl;
		}
		while (sqlite3_step(pStmt) == SQLITE_ROW);
	}

	sqlite3_finalize(pStmt);
	return rc;
}

void catalog(sqlite3 *db) {
	sqlite3_stmt *pStmt;
	sqlite3_prepare_v2(db,"SELECT name, price FROM products", -1, &pStmt, NULL);

	while (sqlite3_step(pStmt) == SQLITE_ROW) {
		string n = (const char*) sqlite3_column_text(pStmt, 0);
		double pr = sqlite3_column_double(pStmt, 1);
		cout << n << " - " << pr << " euro." << endl;
	}

	sqlite3_finalize(pStmt);
}

void summary(sqlite3 *db, string username) {
	// ordini (da pagare)
	cout << "---------------------" << endl << "I tuoi ordini:" << endl << endl;
	listOrd(db, username);

	// acquisti passati
	cout << "---------------------" << endl << "I tuoi acquisti:" << endl << endl;

	sqlite3_stmt *pStmt;
	sqlite3_prepare_v2(db, "SELECT o.pDate, o.product, p.price FROM orders o, products p WHERE user = ? AND paid = 1 AND o.product = p.name", -1, &pStmt, NULL);
	sqlite3_bind_text(pStmt, 1, username.c_str(), -1, SQLITE_STATIC);

	if (sqlite3_step(pStmt) == SQLITE_DONE) {
		cout << "Ancora nessun acquisto." << endl;
	}
	else {
		do {
			string dt = (const char*) sqlite3_column_text(pStmt, 0);
			string p = (const char*) sqlite3_column_text(pStmt, 1);
			double pr = sqlite3_column_double(pStmt, 2);
			cout << dt << " - " << p +", " << pr << " euro." << endl;
		} while (sqlite3_step(pStmt) == SQLITE_ROW);
	}

	sqlite3_finalize(pStmt);

	// prodotti disponibili
	cout << "---------------------" << endl << "Catalogo prodotti:" << endl << endl;
	catalog(db);
	cout <<  "---------------------" << endl;
}

int main()
{
	sqlite3 *db;
	sqlite3_stmt *pStmt;
	sqlite3_open("ecommerce.db", &db);

	string name;
	string lastLogin;
	double maxExp = 1000;

	cout << "#####################################################" << endl;
	cout << "####### Benvenuto nel nostro negozio virtuale #######" << endl;
	cout << "#####################################################" << endl;

	cout << "Username: ";
	string username;
	getline(cin, username);

	int rc = sqlite3_prepare_v2(db, "SELECT name, surname, password, maxExp, regDate, lastLogin FROM users WHERE username = ?", -1, &pStmt, NULL);

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

			try {
				cout << "Limite di spesa: ";
				string d;
				getline(cin, d);
				maxExp = stod(d);
			}
			catch (invalid_argument& e) {
				cerr << e.what() << endl;
			}

			sqlite3_prepare_v2(db, "INSERT INTO users (username, password, name, surname, maxExp, regDate, lastLogin) VALUES (?, ?, ?, ?, ?, ?, ?)", -1, &pStmt, NULL);

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

			sqlite3_bind_double(pStmt, 5, maxExp);

			time_t now = time(NULL);
			struct tm *timeinfo = localtime(&now);

			char date[25];
			strftime(date, sizeof(date), "%d-%m-%Y %H:%M:%S", timeinfo);

			sqlite3_bind_text(pStmt, 6, date, -1, SQLITE_STATIC);
			lastLogin = string(date);

			sqlite3_bind_text(pStmt, 7, date, -1, SQLITE_STATIC);

			if (sqlite3_step(pStmt) == SQLITE_OK) {
				cout << sqlite3_errmsg(db) << endl;
			}

			sqlite3_finalize(pStmt);
		}
		else {
			string name = (const char*) sqlite3_column_text(pStmt, 0);
			string p = (const char*) sqlite3_column_text(pStmt, 2);
			// limite di spesa
			double maxExp = sqlite3_column_double(pStmt, 3);
			lastLogin = (const char*) sqlite3_column_text(pStmt, 5);

			bool auth = false;
			int i = 0; // numero tentativi di autenticazione

			while (!auth) {
				cout << "Password: ";
				string pwd;
				getline(cin, pwd);

				if (pwd != p) {
					i++;
					cout << "Password non corretta!" << endl;
					if (i < 3) continue;
					else {
						cout << "Tre tentativi di autenticazione fallita: stop." << endl;
						return -1;
					}
				}
				auth = true;
			}

			sqlite3_prepare_v2(db, "UPDATE users SET lastLogin = ? WHERE username = ?", -1, &pStmt, NULL);
			time_t now = time(NULL);
			struct tm *timeinfo = localtime(&now);

			char date[25];
			strftime(date, sizeof(date), "%d-%m-%Y %H:%M:%S", timeinfo);

			sqlite3_bind_text(pStmt, 1, date, -1, SQLITE_STATIC);
			sqlite3_bind_text(pStmt, 2, username.c_str(), -1, SQLITE_STATIC);
			sqlite3_step(pStmt);
			sqlite3_finalize(pStmt);
		}

		cout << "Benvenuto, " << name << "!" << endl << "Credito disponibile: " << maxExp << " euro." << endl;
		cout << "Ultimo accesso effettuato il " << lastLogin << "." << endl;

		summary(db, username);

		while (true) {
			cout << "Operazioni disponibili:" << endl << endl;
			cout << "1. Nuovo ordine." << endl;
			cout << "2. Checkup di un ordine." << endl;
			cout << "3. Ricarica credito spesa." << endl;
			cout << "4. Riassunto" << endl;
			cout << "5. Esci" << endl << endl;

			cout << "Scegli l'operazione (1, 2, 3, 4, 5): ";
			string oper;
			getline(cin, oper);

			if (oper == "1") {
				cout << "Disponibili all'acquisto:" << endl << endl;
				catalog(db);

				cout << endl << "Cosa vuoi aggiungere al carrello? ";
				string opt;
				getline(cin, opt);

				sqlite3_stmt *pStmt;
				sqlite3_prepare_v2(db, "SELECT price FROM products WHERE name = ?", -1, &pStmt, NULL);
				sqlite3_bind_text(pStmt, 1, opt.c_str(), -1, SQLITE_STATIC);

				if (sqlite3_step(pStmt) == SQLITE_DONE) {
					cout << "Prodotto non trovato!" << endl << endl;
					continue;
				}

				cout << "Trovato \"" << opt << "\". Vuoi pagare subito? ";
				string p;
				getline(cin, p);

				if (p == "s") {
					double price = sqlite3_column_double(pStmt, 0);
					maxExp -= price;

					sqlite3_finalize(pStmt);

					sqlite3_exec(db, "BEGIN TRANSACTION;", NULL, NULL, NULL);

					sqlite3_prepare_v2(db, "UPDATE users SET maxExp = ? WHERE username = ?", -1, &pStmt, NULL);
					sqlite3_bind_double(pStmt, 1, maxExp);
					sqlite3_bind_text(pStmt, 2, username.c_str(), -1, SQLITE_STATIC);
					sqlite3_step(pStmt);
					sqlite3_finalize(pStmt);

					sqlite3_prepare_v2(db, "INSERT INTO orders (user, product, paid, pDate) VALUES (?, ?, 1, ?)", -1, &pStmt, NULL);
					sqlite3_bind_text(pStmt, 1, username.c_str(), -1, SQLITE_STATIC);
					sqlite3_bind_text(pStmt, 2, opt.c_str(), -1, SQLITE_STATIC);

					time_t now = time(NULL);
					struct tm *timeinfo = localtime(&now);

					char date[25];
					strftime(date, sizeof(date), "%d-%m-%Y %H:%M:%S", timeinfo);

					sqlite3_bind_text(pStmt, 3, date, -1, SQLITE_STATIC);
					sqlite3_step(pStmt);
					sqlite3_finalize(pStmt);

					sqlite3_exec(db, "COMMIT;", NULL, NULL, NULL);
				}
				else {
					sqlite3_prepare_v2(db, "INSERT INTO orders (user, product, paid) VALUES (?, ?, 0)", -1, &pStmt, NULL);
					sqlite3_bind_text(pStmt, 1, username.c_str(), -1, SQLITE_STATIC);
					sqlite3_bind_text(pStmt, 2, opt.c_str(), -1, SQLITE_STATIC);
					sqlite3_step(pStmt);
					sqlite3_finalize(pStmt);
					// sqlite3_bind_int(pStmt, 3;

					// if ( == SQLITE_OK) {
					// 	"Ok!"
					// }
					// else {
					// 	cout << sqlite3_errmsg(db) << endl;
					// }
				}

				cout << endl;
			}
			else if (oper == "2") {
				cout << "Ordini nel carrello:" << endl;

				if (!listOrd(db, username)) continue;

				cout << endl << "Numero ordine da finalizzare: ";
				string s;
				getline(cin, s);

				int oid = -1;
				try {
					oid = stoi(s);
				}
				catch (invalid_argument& e) {
					cerr << e.what() << endl;
				}

				// seleziona il prezzo dell'ordine da evadere
				sqlite3_stmt *pStmt;
				sqlite3_prepare_v2(db, "SELECT p.price FROM orders o, products p WHERE o.id = ? AND o.product = p.name AND o.paid = 0", -1, &pStmt, NULL);
				sqlite3_bind_int(pStmt, 1, oid);
				if (sqlite3_step(pStmt) == SQLITE_DONE) {
					cout << "Ordine non trovato!" << endl << endl;
					continue;
				}

				double price = sqlite3_column_double(pStmt, 0);
				sqlite3_finalize(pStmt);
				maxExp -= price;
				int records = 0;

				sqlite3_exec(db, "BEGIN TRANSACTION;", NULL, NULL, NULL);

				sqlite3_prepare_v2(db, "UPDATE users SET maxExp = ? WHERE username = ?", -1, &pStmt, NULL);
				sqlite3_bind_double(pStmt, 1, maxExp);
				sqlite3_bind_text(pStmt, 2, username.c_str(), -1, SQLITE_STATIC);
				sqlite3_step(pStmt);
				sqlite3_finalize(pStmt);

				sqlite3_prepare_v2(db, "UPDATE orders SET paid = 1, pDate = ? WHERE id = ?", -1, &pStmt, NULL);

				time_t now = time(NULL);
				struct tm *timeinfo = localtime(&now);

				char date[25];
				strftime(date, sizeof(date), "%d-%m-%Y %H:%M:%S", timeinfo);

				sqlite3_bind_text(pStmt, 1, date, -1, SQLITE_STATIC);
				sqlite3_bind_int(pStmt, 2, oid);
				sqlite3_step(pStmt);
				sqlite3_finalize(pStmt);

				sqlite3_exec(db, "COMMIT;", NULL, NULL, NULL);

				records = sqlite3_total_changes(db);

				if (records > 0) {
					cout << "Pagato " << price << " euro. Credito residuo: " << maxExp << " euro." << endl;
				}
			}
			else if (oper == "3") {
				cout << "Importo ricarica: ";
				string imp;
				getline(cin, imp);
				try {
					int v = stoi(imp);

					if (v + maxExp <= 10000) {
						maxExp += v;
						sqlite3_stmt *pStmt;
						sqlite3_prepare_v2(db, "UPDATE users SET maxExp = ? WHERE username = ?", -1, &pStmt, NULL);
						sqlite3_bind_double(pStmt, 1, maxExp);
						sqlite3_bind_text(pStmt, 2, username.c_str(), -1, SQLITE_STATIC);
						// if (sqlite3_step(pStmt) == SQLITE_DONE) {
						// }
						sqlite3_finalize(pStmt);
						cout << "Ricaricato " << imp << " euro. Credito attuale: " << maxExp << " euro." << endl;
					}
				}
				catch (invalid_argument& e) {
					cerr << e.what() << endl;
				}
			}
			else if (oper == "4") {
				summary(db, username);
			}
			else if (oper == "5") {
				cout << "Ciao " << name << ", grazie di aver utilizzato i nostri servizi. A presto!" << endl;
				return 0;
			}
			else {
				cout << "Operazione sconosciuta!" << endl;
			}
		}
	}
	else {
		cerr << sqlite3_errmsg(db) << endl;
	}

	sqlite3_close(db);
}

