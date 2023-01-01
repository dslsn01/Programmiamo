# file esercizio27.py

from __future__ import print_function
import sqlite3

conn = sqlite3.connect("bank.db")
cursor = conn.cursor()

# tabella dei conti deposito che si appoggiano ai conti correnti.

trns  = "PRAGMA foreign_keys = ON;"
trns += "CREATE TABLE deposit (cc VARCHAR, bal REAL, FOREIGN KEY(cc) REFERENCES customers(n_acc));"

try:
	cursor.executescript(trns)
	conn.commit()

	print("Creata tabella dei depositi.")

except sqlite3.OperationalError as e:
	print(e)

