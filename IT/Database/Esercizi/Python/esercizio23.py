# file esercizio23.py

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input
from datetime import date
import sqlite3

conn = sqlite3.connect("users.db", detect_types=sqlite3.PARSE_DECLTYPES | sqlite3.PARSE_COLNAMES)
cursor = conn.cursor()

try:
	cursor.execute("CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, username VARCHAR UNIQUE NOT NULL, password VARCHAR NOT NULL, name VARCHAR NOT NULL, surname VARCHAR NOT NULL, r_date DATE, CHECK(LENGTH(username) <= 50), CHECK(LENGTH(password) <= 50))")
	conn.commit()

	# nome e data di registrazione
	name = ""
	r_date = None

	print("##################################")
	print("####### Schermata di login #######")
	print("##################################")

	username = input("Username: ").lower()

	pStmt = "SELECT name, surname, password, r_date FROM users WHERE username = ?"

	cursor.execute(pStmt, (username,))
	res = cursor.fetchone()

	if not res:
		opt = input("Username \"{}\" non presente! Vuoi registrarti? s | n: ".format(username)).lower()

		if opt != "s": exit()

		pStmt = "INSERT INTO users (username, password, name, surname, r_date) VALUES (?, ?, ?, ?, ?)"

		pwd = input("Password: ") or None
		name = input("Nome: ") or None
		surname = input("Cognome: ") or None

		r_date = date.today()
		cursor.execute(pStmt, (username, pwd, name, surname, r_date))
		conn.commit()
	else:
		auth = False
		i = 0 # numero tentativi di autenticazione
		_pwd = res[2]
		while not auth:
			pwd = input("Password: ")
			if pwd != _pwd:
				i += 1
				print("Password non corretta!")
				if i < 3: continue
				else:
					print("Tre tentativi di autenticazione fallita: stop.")
					exit()

			auth = True

		name = res[0]
		# data di registrazione
		r_date = res[3]

	print("++++++++++++++++++++++++++++++++++")
	print("Benvenuto, {}!\nSei registrato dal {}.".format(name, r_date.strftime("%d/%m/%Y")))

except sqlite3.OperationalError as e:
	print(e)

