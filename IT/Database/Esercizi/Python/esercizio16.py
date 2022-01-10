# file esercizio16.py

from __future__ import print_function
import sqlite3

conn = sqlite3.connect("students.db")
cursor = conn.cursor()

try:
	cursor.execute("DELETE FROM students WHERE grade IS NOT NULL")
	conn.commit()
	print("Rimossi studenti che hanno superato l'esame.")

except sqlite3.OperationalError as e:
	print(e)

