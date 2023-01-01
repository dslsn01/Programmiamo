# file esercizio19.py

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input
import sqlite3

conn = sqlite3.connect("videostore.db")
cursor = conn.cursor()
records = 0

try:
	cursor.execute("CREATE TABLE IF NOT EXISTS movies (id INTEGER PRIMARY KEY, title VARCHAR UNIQUE NOT NULL, year INTEGER, director VARCHAR NOT NULL, star VARCHAR, CHECK(LENGTH(title) <= 255), CHECK(LENGTH(year) == 4), CHECK(LENGTH(director) <= 255), CHECK(LENGTH(star) <= 255))")

	print("Film da salvare (stringa vuota per uscire).")

	while True:
		try:
			title = input("Titolo film: ")

			if not title: break;

			yr = None

			try:
				s = input("Anno: ")
				if s: yr = int(s)
			except ValueError as e:
				print(e)

			director = input("Regista: ") or None
			star = input("Attore principale: ") or None

			cursor.execute("INSERT INTO movies (title, year, director, star) values (?, ?, ?, ?)", (title, yr, director, star))
			records += cursor.rowcount
		except sqlite3.IntegrityError as e:
			print(e)

	conn.commit()
	print("Registrati {} film.".format(records))

except sqlite3.OperationalError as e:
	print(e)

