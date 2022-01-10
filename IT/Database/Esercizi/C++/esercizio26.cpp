/*
file esercizio26.cpp
compilare con: g++ -std=c++11 esercizio26.cpp
*/

#include <iostream>
#include <stdexcept>
#include <ctime>
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

	cout << "#####################################################" << endl;
	cout << "######## Amministrazione clienti della banca ########" << endl;
	cout << "#####################################################" << endl;

	int rc = sqlite3_prepare_v2(db, "SELECT n_acc, ident, bal FROM customers", -1, &pStmt, NULL);

	if (rc != SQLITE_ERROR) {
		while (sqlite3_step(pStmt) == SQLITE_ROW) {
			string n_acc = (const char*) sqlite3_column_text(pStmt, 0);
			string ident = (const char*) sqlite3_column_text(pStmt, 1);
			double bal = sqlite3_column_double(pStmt, 2);
			cout << "[" << n_acc << "] - " << ident << ", " << bal << " euro." << endl;
		}

		sqlite3_finalize(pStmt);

		while (true) {
			cout << "Registra un nuovo movimento (entrata / uscita): " << endl;

			cout << "Numero conto: ";
			string cc;
			getline(cin, cc);

			if (cc.empty()) return 0;

			sqlite3_prepare_v2(db, "SELECT bal, iban FROM customers WHERE n_acc = ?", -1, &pStmt, NULL);
			sqlite3_bind_text(pStmt, 1, cc.c_str(), -1, SQLITE_STATIC);

			if (sqlite3_step(pStmt) == SQLITE_DONE) {
				cerr << "!!! Conto non esistente!" << endl;
				sqlite3_finalize(pStmt);
				continue;
			}

			double pbal = sqlite3_column_double(pStmt, 0);
			string iban = (const char*) sqlite3_column_text(pStmt, 1);
			double sbal = 0.0;
			double imp = 0.0;

			cout << "Importo (accredito o addebito): ";
			string i;
			getline(cin, i);

			// incrementa o decrementa il saldo
			try {
				imp = stod(i);
				pbal += imp;
			}
			catch (invalid_argument& e) {
				cerr << e.what() << endl;
				continue;
			}

			if (!imp) {
				cerr << "!!! Importo non valido!" << endl;
				continue;
			}

			// IBAN letto da tastiera
			string s;
			// IBAN ordinante e beneficiario
			string o_iban;
			string b_iban;

			// movimento in uscita
			if (imp < 0) {
				cout << "IBAN beneficiario (27 cifre): ";
				getline(cin, s);

				if (s.empty()) {
					cerr << "!!! IBAN beneficiario nullo!" << endl;
					continue;
				}

				b_iban = s;
				// IBAN associato a conto corrente
				o_iban = iban;
			}

			// movimento in entrata
			else if (imp > 0) {
				cout << "IBAN ordinante (27 cifre): ";
				getline(cin, s);

				if (s.empty()) {
					cerr << "!!! IBAN ordinante nullo!" << endl;
					continue;
				}

				o_iban = s;
				// IBAN associato a conto corrente
				b_iban = iban;
			}

			sqlite3_finalize(pStmt);

			if (o_iban == b_iban) {
				cerr << "!!! IBAN di ordinante e beneficiario coincidono!" << endl;
				continue;
			}

			// recupera le coordinate del secondo conto
			sqlite3_prepare_v2(db, "SELECT bal FROM customers WHERE iban = ?", -1, &pStmt, NULL);
			sqlite3_bind_text(pStmt, 1, s.c_str(), -1, SQLITE_STATIC);

			if (sqlite3_step(pStmt) == SQLITE_DONE) {
				cerr << "!!! Conto non esistente!" << endl;
				sqlite3_finalize(pStmt);
				continue;
			}

			// incrementa/decrementa il saldo dell'altro conto corrente
			sbal = sqlite3_column_double(pStmt, 0) - imp;
			// string icc = (const char*) sqlite3_column_text(pStmt, 1);
			//ibal +

			sqlite3_finalize(pStmt);

			string desc;
			cout << "Descrizione/causale: ";
			getline(cin, desc);

			sqlite3_exec(db, "BEGIN TRANSACTION;", NULL, NULL, NULL);

			sqlite3_prepare_v2(db, "INSERT INTO mov (ord, ben, imp, desc, v_date, o_date) VALUES (?, ?, ?, ?, ?, ?)", -1, &pStmt, NULL);
			// cout << "o_iban: " << o_iban << ", b_iban: " << b_iban << endl;
			sqlite3_bind_text(pStmt, 1, o_iban.c_str(), -1, SQLITE_STATIC);
			sqlite3_bind_text(pStmt, 2, b_iban.c_str(), -1, SQLITE_STATIC);
			// l'importo del movimento viene registrato in valore assoluto
			sqlite3_bind_double(pStmt, 3, abs(imp));
			sqlite3_bind_text(pStmt, 4, desc.c_str(), -1, SQLITE_STATIC);

			time_t now = time(NULL);
			struct tm *timeinfo = localtime(&now);
			char v_date[15];
			strftime(v_date, sizeof(v_date), "%Y-%m-%d", timeinfo);

			timeinfo->tm_mday += 3;
			char o_date[15];
			strftime(o_date, sizeof(o_date), "%Y-%m-%d", timeinfo);

			sqlite3_bind_text(pStmt, 5, v_date, -1, SQLITE_STATIC);
			sqlite3_bind_text(pStmt, 6, o_date, -1, SQLITE_STATIC);

			sqlite3_step(pStmt);
			sqlite3_finalize(pStmt);

			// aggiorna entrambi i conti
			sqlite3_prepare_v2(db, "UPDATE customers SET bal = ? WHERE n_acc = ?", -1, &pStmt, NULL);
			sqlite3_bind_double(pStmt, 1, pbal);
			sqlite3_bind_text(pStmt, 2, cc.c_str(), -1, SQLITE_STATIC);
			sqlite3_step(pStmt);
			sqlite3_finalize(pStmt);

			sqlite3_prepare_v2(db, "UPDATE customers SET bal = ? WHERE iban = ?", -1, &pStmt, NULL);
			sqlite3_bind_double(pStmt, 1, sbal);
			sqlite3_bind_text(pStmt, 2, s.c_str(), -1, SQLITE_STATIC);
			sqlite3_step(pStmt);
			sqlite3_finalize(pStmt);

			sqlite3_exec(db, "COMMIT;", NULL, NULL, NULL);
		}
	}
	else {
		cerr << sqlite3_errmsg(db) << endl;
	}

	sqlite3_close(db);
}

