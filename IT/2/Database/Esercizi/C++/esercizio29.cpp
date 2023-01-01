/* file esercizio30.cpp */

#include <iostream>
#include <sqlite3.h>

using std::string;
using std::cerr;
using std::cout;
using std::endl;

int main()
{
	sqlite3 *db;
	sqlite3_open("ecommerce.db", &db);

	string transaction = "BEGIN TRANSACTION;";
	transaction += "PRAGMA foreign_keys = ON;";
	transaction += "CREATE TABLE users (id INTEGER PRIMARY KEY, username VARCHAR(50) UNIQUE NOT NULL, password VARCHAR(50) NOT NULL, name VARCHAR(50) NOT NULL, surname VARCHAR(50) NOT NULL, maxExp REAL NOT NULL, r_date TIMESTAMP, llogin TIMESTAMP);";
	transaction += "CREATE TABLE products (name VARCHAR(255) PRIMARY KEY, price REAL);";
	transaction += "CREATE TABLE orders (id INTEGER PRIMARY KEY, user VARCHAR(50), product VARCHAR(255), paid BIT, pDate TIMESTAMP, FOREIGN KEY(user) REFERENCES users(username), FOREIGN KEY(product) REFERENCES products(name));";
	transaction += "INSERT INTO products (name, price) VALUES ('Apple IPhone', 1000);";
	transaction += "INSERT INTO products (name, price) VALUES ('Apple IPad Pro', 399);";
	transaction += "INSERT INTO products (name, price) VALUES ('Apple MacPro', 6599);";
	transaction += "INSERT INTO products (name, price) VALUES ('Lenovo ThinkPad', 1159);";
	transaction += "INSERT INTO products (name, price) VALUES ('Lenovo P', 1348.9);";
	transaction += "COMMIT;";

	int rc = sqlite3_exec(db, transaction.c_str(), NULL, NULL, NULL);

	if (rc == SQLITE_OK) {
		cout << "Create le tabelle di utenti, prodotti e ordini." << endl;
	}
	else {
		cerr << sqlite3_errmsg(db) << endl;
	}

	sqlite3_close(db);
}

