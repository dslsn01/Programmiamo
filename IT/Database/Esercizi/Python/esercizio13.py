# file esercizio13.py

from __future__ import print_function
import sqlite3

conn = sqlite3.connect("students.db")
cursor = conn.cursor()

try:
	cursor.execute("SELECT AVG(grade) FROM students")
	v = cursor.fetchone()[0]

	if not v:
		print("Nessuno studente ha ancora passato l'esame.")
		exit()

	print("Voto medio: {}".format(v))

except sqlite3.OperationalError as e:
	print(e)

