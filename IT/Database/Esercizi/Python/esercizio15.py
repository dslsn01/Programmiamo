# file esercizio15.py

from __future__ import print_function
import sqlite3

conn = sqlite3.connect("students.db")
cursor = conn.cursor()

try:
	query  = "SELECT a.number, a.name, a.surname, a.grade "
	query += "FROM students a "
	query += "INNER JOIN ("
	query += "SELECT MIN(grade) AS grade FROM students"
	query += ") b ON a.grade = b.grade"

	cursor.execute(query)

	for student in cursor.fetchall(): 
		print("Matricola {}, {} {}, voto: {}".format(student[0], student[1], student[2], student[3]))

except sqlite3.OperationalError as e:
	print(e)

