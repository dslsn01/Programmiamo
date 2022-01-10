# file esercizio8.py

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input
import sqlite3

print("Inserisci gli studenti del corso (matricola vuota per uscire).")

conn = sqlite3.connect("students.db")
cursor = conn.cursor()
records = 0

while True:
	try:
		num = input("Numero di matricola: ") or None

		if not num: break

		name = input("Nome: ") or None
		surname = input("Cognome: ") or None
		age = None
		s1 = input("Anni: ")
		grade = None
		s2 = input("Voto d'esame: ") or None

		try:
			age = int(s1)
			tmp = int(s2)
			if tmp >= 18 or tmp <= 30: grade = tmp
			else: print("Voto non valido!")
		except ValueError as e:
			print(e)

		cursor.execute("INSERT INTO students (number, name, surname, age, grade) VALUES (?, ?, ?, ?, ?)", (num, name, surname, age, grade))
		records += cursor.rowcount

	except ValueError as e:
		print(e)

	except sqlite3.OperationalError as e:
		print(e)

	except sqlite3.IntegrityError as e:
		print(e)

if records > 0: conn.commit()
print("Registrati {} studenti.".format(records))

