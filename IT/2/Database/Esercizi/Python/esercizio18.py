# file esercizio18.py

from __future__ import print_function
import sqlite3

conn = sqlite3.connect("videostore.db")
cursor = conn.cursor()

try:
	cursor.execute("SELECT title, year FROM movies")

	res = cursor.fetchall()

	if not res:
		print("Nessun film disponibile in videoteca!")
		exit()

	for film in res:
		s = film[0]
		yr = film[1]
		if yr: s += " ({})".format(yr)
		s += "."
		print(s)

except sqlite3.OperationalError as e:
	print(e)

