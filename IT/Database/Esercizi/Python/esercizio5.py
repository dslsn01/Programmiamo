# file esercizio5.py

from __future__ import print_function
import sqlite3

conn = sqlite3.connect("students.db")
cursor = conn.cursor()

try:
	cursor.execute("DROP TABLE students")
	conn.commit()
	print("Tabella degli studenti eliminata.")

except sqlite3.OperationalError as e:
	print(e)

