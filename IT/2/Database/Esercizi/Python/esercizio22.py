# file esercizio22.py

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input
import sqlite3

conn = sqlite3.connect("users.db")
cursor = conn.cursor()

try:
	cursor.execute("CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, username VARCHAR UNIQUE NOT NULL, password VARCHAR NOT NULL, name VARCHAR NOT NULL, surname VARCHAR NOT NULL, CHECK(LENGTH(username) <= 50), CHECK(LENGTH(password) <= 50))")
	conn.commit()

	# nome
	name = ""

	print("##################################")
	print("####### Schermata di login #######")
	print("##################################")

	username = input("Username: ").lower()

	pStmt = "SELECT name, surname, password FROM users WHERE username = ?"

	cursor.execute(pStmt, (username,))
	res = cursor.fetchone()

	if not res:
		opt = input("Username \"{}\" non presente! Vuoi registrarti? s | n: ".format(username)).lower()

		if opt != "s": exit()

		pStmt = "INSERT INTO users (username, password, name, surname) VALUES (?, ?, ?, ?)"

		pwd = input("Password: ") or None
		name = input("Nome: ") or None
		surname = input("Cognome: ") or None

		cursor.execute(pStmt, (username, pwd, name, surname))
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

		# nome
		name = res[0]

	print("++++++++++++++++++++++++++++++++++")
	print("Benvenuto, {}!".format(name))

except sqlite3.OperationalError as e:
	print(e)

