/*
file esercizio28.cpp
compilare con: g++ -std=c++11 esercizio28.cpp
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

int main()
{
	sqlite3 *db;
	sqlite3_stmt *pStmt;
	sqlite3_open("bank.db", &db);

	cout << "##############################################" << endl;
	cout << "####### Benvenuto nel sito della banca #######" << endl;
	cout << "##############################################" << endl;

	cout << "Codice utente: ";
	string ucode;
	getline(cin, ucode);

	sqlite3_prepare_v2(db, "SELECT n_acc, iban, password, ident, bal FROM customers WHERE ucode = ?", -1, &pStmt, NULL);
	sqlite3_bind_text(pStmt, 1, ucode.c_str(), -1, SQLITE_STATIC);

	if (sqlite3_step(pStmt) == SQLITE_DONE) {
		cerr << "Utente \"" + ucode + "\" non presente!" << endl;
		return -1;
	}

	bool auth = false;
	int i = 0; // numero tentativi di autenticazione

	string _pwd = (const char*) sqlite3_column_text(pStmt, 2);

	while (!auth) {
		cout << "Password: ";
		string pwd;
		getline(cin, pwd);

		if (pwd != _pwd) {
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

	string n_acc = (const char*) sqlite3_column_text(pStmt, 0);
	string iban = (const char*) sqlite3_column_text(pStmt, 1);
	string ident = (const char*) sqlite3_column_text(pStmt, 3);
	double bal = sqlite3_column_double(pStmt, 4);

	sqlite3_finalize(pStmt);

	cout << "Benvenuto, " << ident << "!" << endl << "N. conto: " << n_acc << " IBAN: " << iban << endl;
	cout << "Saldo conto: " << bal << " euro." << endl;

	while (true) {
		cout << "Operazioni disponibili:" << endl << endl;
		cout << "1. Lista movimenti." << endl;
		cout << "2. Bonifico." << endl;
		cout << "3. Esplora conto deposito." << endl;
		cout << "4. Esci\n" << endl;

		cout << "Scegli l'operazione (1, 2, 3, 4): ";
		string oper;
		getline(cin, oper);

		if (oper == "1") {
			cout << "Lista movimenti" << endl << endl;

			sqlite3_prepare_v2(db, "SELECT ord, imp, desc, v_date, o_date FROM mov WHERE (ord = ? OR ben = ?)", -1, &pStmt, NULL);
			sqlite3_bind_text(pStmt, 1, iban.c_str(), -1, SQLITE_STATIC);
			sqlite3_bind_text(pStmt, 2, iban.c_str(), -1, SQLITE_STATIC);

			if (sqlite3_step(pStmt) == SQLITE_DONE) {
				cout << "Nessun movimento recente." << endl << endl;
				continue;
			}

			do {
				string ord = (const char*) sqlite3_column_text(pStmt, 0);
				double imp = sqlite3_column_double(pStmt, 1);
				// i versamenti sono movimenti negativi
				imp = ord == iban ? -imp : imp;
				string desc = (const char*) sqlite3_column_text(pStmt, 2);
				string v_date = (const char*) sqlite3_column_text(pStmt, 3);
				string o_date = (const char*) sqlite3_column_text(pStmt, 4);
				cout << imp << " euro - \"" << desc << "\", data valuta: " << v_date << " data operativa: " << o_date << endl;
			} while (sqlite3_step(pStmt) == SQLITE_ROW);

			sqlite3_finalize(pStmt);
			cout << endl;
		}
		else if (oper == "2") {
			cout << "Bonifico" << endl;

			cout << "IBAN beneficiario: ";
			string b_iban;
			getline(cin, b_iban);

			if (b_iban == iban) continue;

			sqlite3_prepare_v2(db, "SELECT ident, bal FROM customers WHERE iban = ?", -1, &pStmt, NULL);
			sqlite3_bind_text(pStmt, 1, b_iban.c_str(), -1, SQLITE_STATIC);

			if (sqlite3_step(pStmt) == SQLITE_DONE) {
				cout << "IBAN non esistente!" << endl;
				continue;
			}

			string b = (const char*) sqlite3_column_text(pStmt, 0);
			cout << "Beneficiario: " << b << endl;
			double d_bal = sqlite3_column_double(pStmt, 1);

			sqlite3_finalize(pStmt);

			cout << "Importo bonifico: ";
			string s;
			getline(cin, s);

			double imp = 0;
			try {
				imp = stod(s);
				if (bal - imp < 0) {
					cout << "Conto incapiente!" << endl;
					continue;
				}
				bal -= imp;
				d_bal += imp;
			}
			catch (invalid_argument& e) {
				cerr << e.what() << endl;
				continue;
			}

			cout << "Descrizione/causale: ";
			string desc;
			getline(cin, desc);

			// aggiorna saldo conto corrente, tabella movimenti, saldo conto destinatario?

			sqlite3_exec(db, "BEGIN TRANSACTION;", NULL, NULL, NULL);

			sqlite3_prepare_v2(db, "UPDATE customers SET bal = ? WHERE iban = ?", -1, &pStmt, NULL);
			sqlite3_bind_double(pStmt, 1, bal);
			sqlite3_bind_text(pStmt, 2, iban.c_str(), -1, SQLITE_STATIC);
			sqlite3_step(pStmt);
			sqlite3_finalize(pStmt);

			sqlite3_prepare_v2(db, "INSERT INTO mov (ord, ben, imp, desc, v_date, o_date) VALUES (?, ?, ?, ?, ?, ?)", -1, &pStmt, NULL);
			sqlite3_bind_text(pStmt, 1, iban.c_str(), -1, SQLITE_STATIC);
			sqlite3_bind_text(pStmt, 2, b_iban.c_str(), -1, SQLITE_STATIC);
			sqlite3_bind_double(pStmt, 3, imp);
			sqlite3_bind_text(pStmt, 4, desc.c_str(), -1, SQLITE_STATIC);

			time_t now = time(NULL);
			struct tm *timeinfo = localtime(&now);
			char v_date[25];
			strftime(v_date, sizeof(v_date), "%d-%m-%Y", timeinfo);

			sqlite3_bind_text(pStmt, 5, v_date, -1, SQLITE_STATIC);

			timeinfo->tm_mday += 3;
			char o_date[25];
			strftime(o_date, sizeof(o_date), "%d-%m-%Y", timeinfo);

			sqlite3_bind_text(pStmt, 6, o_date, -1, SQLITE_STATIC);

			sqlite3_step(pStmt);
			sqlite3_finalize(pStmt);

			sqlite3_prepare_v2(db, "UPDATE customers SET bal = ? WHERE iban = ?", -1, &pStmt, NULL);
			sqlite3_bind_double(pStmt, 1, d_bal);
			sqlite3_bind_text(pStmt, 2, b_iban.c_str(), -1, SQLITE_STATIC);
			sqlite3_step(pStmt);
			sqlite3_finalize(pStmt);

			if (sqlite3_total_changes(db) > 0) {
				sqlite3_exec(db, "COMMIT;", NULL, NULL, NULL);
				cout << "Inviato bonifico di " << imp << " euro a " << b << "." << endl;
			}

			cout << endl;
		}
		else if (oper == "3") {
			cout << "Esplora conto deposito" << endl;

			sqlite3_prepare_v2(db, "SELECT bal FROM deposit WHERE cc = ?", -1, &pStmt, NULL);
			sqlite3_bind_text(pStmt, 1, n_acc.c_str(), -1, SQLITE_STATIC);

			double imp = 0;
			double d_bal = 0;

			if (sqlite3_step(pStmt) == SQLITE_DONE) {
				sqlite3_finalize(pStmt);

				cout << "Conto deposito non ancora aperto. Si desidera aprirlo? s | n: ";
				string opt;
				getline(cin, opt); // .toLowerCase()

				if (opt != "s") continue;

				sqlite3_prepare_v2(db, "INSERT INTO deposit (cc, bal) VALUES (?, 0)", -1, &pStmt, NULL);
				sqlite3_bind_text(pStmt, 1, n_acc.c_str(), -1, SQLITE_STATIC);
				sqlite3_step(pStmt);
				sqlite3_finalize(pStmt);
			}
			else {
				// saldo conto deposito
				d_bal = sqlite3_column_double(pStmt, 1);
				sqlite3_finalize(pStmt);
			}

			cout << "Operazioni disponibili:" << endl << endl;
			cout << "a. Trasferisci fondi da conto corrente a conto deposito." << endl;
			cout << "b. Trasferisci fondi da conto deposito a conto corrente." << endl << endl;

			cout << "Scegli l'operazione (a/b): ";
			string op;
			getline(cin, op);

			if (op != "a" && op != "b") {
				cerr << "Operazione sconosciuta!" << endl;
				continue;
			}

			cout << "Importo: ";
			string s;
			getline(cin, s);

			try {
				imp = stod(s);
			}
			catch (invalid_argument& e) {
				cerr << e.what() << endl;
				continue;
			}

			if (op == "a") {
				if (bal - imp >= 0) {
					// decrementa saldo conto corrente
					bal -= imp;
					// incrementa saldo conto deposito
					d_bal += imp;
				} else {
					cerr << "Importo non disponibile su conto corrente!" << endl;
					continue;
				}
			}
			else {
				if (d_bal - imp >= 0) {
					d_bal -= imp;
					bal += imp;
				} else {
					cerr << "Importo non disponibile su conto deposito!" << endl;
					continue;
				}
			}

			sqlite3_exec(db, "BEGIN TRANSACTION;", NULL, NULL, NULL);

			sqlite3_prepare_v2(db, "UPDATE customers SET bal = ? WHERE n_acc = ?", -1, &pStmt, NULL);
			sqlite3_bind_double(pStmt, 1, bal);
			sqlite3_bind_text(pStmt, 2, n_acc.c_str(), -1, SQLITE_STATIC);
			sqlite3_step(pStmt);
			sqlite3_finalize(pStmt);

			sqlite3_prepare_v2(db, "UPDATE deposit SET bal = ? WHERE cc = ?", -1, &pStmt, NULL);
			sqlite3_bind_double(pStmt, 1, d_bal);
			sqlite3_bind_text(pStmt, 2, n_acc.c_str(), -1, SQLITE_STATIC);
			sqlite3_step(pStmt);
			sqlite3_finalize(pStmt);

			if (sqlite3_total_changes(db) > 0) {
				sqlite3_exec(db, "COMMIT;", NULL, NULL, NULL);
				cout << "Inviato bonifico di " << imp << " euro a " << ident << "." << endl;
			}

			cout << endl;

			string msg = op == "b" ? "corrente" : "deposito";
			cout << "Trasferiti " << imp << " euro su conto " << msg << "." << endl << endl;
		}
		else if (oper == "4") {
			cout << "Grazie di aver utilizzato i servizi della banca." << endl;
			return 0;
		}
		else {
			cout << "Operazione sconosciuta!" << endl << endl;
		}
	}
}

