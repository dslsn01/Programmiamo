# file esercizio10.py
# -*- coding: utf-8 -*-

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input
import sqlite3

print("Elimina uno o più studenti.")

conn = sqlite3.connect("students.db")
cursor = conn.cursor()
records = 0

try:
	cursor.execute("SELECT number, name, surname FROM students")

	for s in cursor.fetchall():
		num = s[0]
		print("Matricola {}, {} {}".format(num, s[1], s[2]))
		opt = input("Rimuovere lo studente dal corso? ")

		if not opt == "s": continue

		cursor.execute("DELETE FROM students WHERE number = ?", (num,))
		records += 1

except sqlite3.OperationalError as e:
	print(e)

if records > 0: conn.commit()
print("Eliminati {} nominativi di studenti.".format(records))

