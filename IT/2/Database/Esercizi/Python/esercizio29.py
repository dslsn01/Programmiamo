# file esercizio29.py

from __future__ import print_function
import sqlite3

conn = sqlite3.connect("ecommerce.db")
cursor = conn.cursor()

try:
	transaction  = "PRAGMA foreign_keys = ON;"
	transaction += "CREATE TABLE users (id INTEGER PRIMARY KEY, username VARCHAR(50) UNIQUE NOT NULL, password VARCHAR(50) NOT NULL, name VARCHAR(50) NOT NULL, surname VARCHAR(50) NOT NULL, maxExp REAL NOT NULL, r_date TIMESTAMP, llogin TIMESTAMP);"
	transaction += "CREATE TABLE products (name VARCHAR(255) PRIMARY KEY, price REAL);"
	transaction += "CREATE TABLE orders (id INTEGER PRIMARY KEY, user VARCHAR(50), product VARCHAR(255), paid BIT, pDate TIMESTAMP, FOREIGN KEY(user) REFERENCES users(username), FOREIGN KEY(product) REFERENCES products(name));"
	transaction += "INSERT INTO products (name, price) VALUES ('Apple IPhone', 1000);"
	transaction += "INSERT INTO products (name, price) VALUES ('Apple IPad Pro', 399);"
	transaction += "INSERT INTO products (name, price) VALUES ('Apple MacPro', 6599);"
	transaction += "INSERT INTO products (name, price) VALUES ('Lenovo ThinkPad', 1159);"
	transaction += "INSERT INTO products (name, price) VALUES ('Lenovo P', 1348.9);"

	cursor.executescript(transaction)
	conn.commit()

	print("Create le tabelle di utenti, prodotti e ordini.")

except sqlite3.OperationalError as e:
	print(e)

