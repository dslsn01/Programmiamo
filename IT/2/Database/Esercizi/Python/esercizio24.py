# file esercizio.py

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input
from datetime import date, datetime
import sqlite3

conn = sqlite3.connect("users.db", detect_types=sqlite3.PARSE_DECLTYPES | sqlite3.PARSE_COLNAMES)
cursor = conn.cursor()

try:
	cursor.execute("CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, username VARCHAR UNIQUE NOT NULL, password VARCHAR NOT NULL, name VARCHAR NOT NULL, surname VARCHAR NOT NULL, r_date DATE, llogin TIMESTAMP, CHECK(LENGTH(username) <= 50), CHECK(LENGTH(password) <= 50))")
	conn.commit()

	# nome, data di registrazione e ultimo login
	name = ""
	r_date = None
	llogin = None

	print("##################################")
	print("####### Schermata di login #######")
	print("##################################")

	username = input("Username: ").lower()

	pStmt = "SELECT name, surname, password, r_date, llogin FROM users WHERE username = ?"

	cursor.execute(pStmt, (username,))
	res = cursor.fetchone()

	if not res:
		opt = input("Username \"{}\" non presente! Vuoi registrarti? s | n: ".format(username)).lower()

		if opt != "s": exit()

		pStmt = "INSERT INTO users (username, password, name, surname, r_date, llogin) VALUES (?, ?, ?, ?, ?, ?)"

		pwd = input("Password: ") or None
		name = input("Nome: ") or None
		surname = input("Cognome: ") or None

		dt = datetime.now().replace(microsecond=0)
		r_date = dt.date()
		llogin = dt
		cursor.execute(pStmt, (username, pwd, name, surname, r_date, llogin))
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

			llogin = datetime.now().replace(second=0, microsecond=0)
			cursor.execute("UPDATE users SET llogin = ? WHERE username = ?", (llogin, username))
			conn.commit()

		name = res[0]
		r_date = res[3]
		# data ultimo accesso
		llogin = res[4]

	print("++++++++++++++++++++++++++++++++++")
	print("Benvenuto, {}!\nSei registrato dal {}.\nUltimo accesso effettuato il {}.".format(name, r_date.strftime("%d/%m/%Y"), llogin.strftime("%d/%m/%Y %H:%M:%S")))

except sqlite3.OperationalError as e:
	print(e)

