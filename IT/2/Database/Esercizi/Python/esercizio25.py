# file esercizio25.py
# -*- coding: utf-8 -*-

from __future__ import print_function
import sqlite3

conn = sqlite3.connect("bank.db")
cursor = conn.cursor()

# tabella clienti: codice utente e password (almeno 8 cifre), numero conto (12 cifre), iban (27 cifre in italia) e saldo conto
# tabella movimenti: intestatario del conto, importo, casuale/descrizione, data valuta, data operativa.

trns  = "PRAGMA foreign_keys = ON;"
trns += "CREATE TABLE customers (n_acc VARCHAR PRIMARY KEY, iban VARCHAR UNIQUE NOT NULL, ucode INTEGER NOT NULL, password VARCHAR NOT NULL, ident VARCHAR, bal REAL, CHECK(LENGTH(n_acc) == 12), CHECK(LENGTH(ucode) == 8), CHECK(LENGTH(password) == 8), CHECK(LENGTH(iban) == 27));"
trns += "CREATE TABLE mov (id INTEGER PRIMARY KEY, ord VARCHAR, ben VARCHAR, imp REAL, desc VARCHAR, v_date DATE, o_date DATE, FOREIGN KEY(ord) REFERENCES customers(iban), FOREIGN KEY(ben) REFERENCES customers(iban));"

try:
	cursor.executescript(trns)
	# esegue il commit della transazione
	conn.commit()

	print("Create le tabelle di clienti e movimenti.")

	# inserisce quattro clienti di prova
	insert  = "INSERT INTO customers (n_acc, iban, ucode, password, ident, bal) VALUES ('000009753468', 'IT02S0300203280881249519873', 75310246, 'foobarba', 'Mario Rossi', 1000);"
	insert += "INSERT INTO customers (n_acc, iban, ucode, password, ident, bal) VALUES ('000007986541', 'IT96W0300203280997548569793', 21304152, 'barbazfo', 'Luigi Bianchi', 1500);"
	insert += "INSERT INTO customers (n_acc, iban, ucode, password, ident, bal) VALUES ('000001753429', 'IT80H0300203280392486464466', 30415263, 'bazfooba', 'Giovanni Verdi', 2500);"
	insert += "INSERT INTO customers (n_acc, iban, ucode, password, ident, bal) VALUES ('000009078653', 'IT97E0300203280833549251697', 16180339, '1,7O9975', 'Fondo di investimento', 10000000);"

	cursor.executescript(insert)
	conn.commit()

	print("La banca ha quattro nuovi clienti!")

except sqlite3.OperationalError as e:
	print(e)

