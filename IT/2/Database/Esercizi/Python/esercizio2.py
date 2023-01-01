# file esercizio2.py

from __future__ import print_function
import sqlite3

conn = sqlite3.connect("students.db")
cursor = conn.cursor()

try:
	cursor.execute("SELECT COUNT(*) FROM students")

	if cursor.fetchone()[0] > 0:
		print("Tabella degli studenti non vuota!")
		exit()

	cursor.execute("INSERT INTO students (number, name, surname, age) VALUES ('A23234', 'Mario', 'Rossi', 19)")
	cursor.execute("INSERT INTO students (number, name, surname, age) VALUES ('A01357', 'Luigi', 'Bianchi', 20)")
	cursor.execute("INSERT INTO students (number, name, surname, age) VALUES ('A12579', 'Giovanni', 'Verdi', 20)")

	conn.commit()

	print("Tre nuovi studenti iscritti al corso.")

except sqlite3.OperationalError as e:
	print(e)

