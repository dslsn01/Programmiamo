# file esercizio9.py

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input
import sqlite3

print("Aggiorna il voto d'esame degli studenti.")

conn = sqlite3.connect("students.db")
cursor = conn.cursor()
records = 0

try:
	cursor.execute("SELECT number, name, surname FROM students")
	res = cursor.fetchall()

	if not res:
		print("Non ci sono studenti iscritti al corso!")
		exit()

	for r in res:
		num = r[0]
		print("Matricola {}, {} {}".format(num, r[1], r[2]))
		s = input("Voto (da 18 a 30): ")

		if not s: continue

		try:
			grade = int(s)
 			if grade < 18 or grade > 30:
				print("Voto non valido!")
				continue
		except ValueError as e:
			print(e)
			continue

		cursor.execute("UPDATE students SET grade = ? WHERE number = ?", (grade, num,))
		records += cursor.rowcount

except sqlite3.OperationalError as e:
	print(e)
except sqlite3.ProgrammingError as e:
	print(e)

if records > 0: conn.commit()
print("{} studenti hanno passato la prova d'esame.".format(records))

