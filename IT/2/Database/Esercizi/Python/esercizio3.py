# file esercizio3.py

from __future__ import print_function
import sqlite3

conn = sqlite3.connect("students.db")
cursor = conn.cursor()

try:
	cursor.execute("SELECT number, name, surname FROM students")
	res = cursor.fetchall()

	if not res:
		print("Non ci sono studenti iscritti al corso!")
		exit()

	for student in res:
		print("Matricola {}, {} {}.".format(student[0], student[1], student[2]))

except sqlite3.OperationalError as e:
	print(e)

