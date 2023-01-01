# file esercizio7.py

from __future__ import print_function
import sqlite3

conn = sqlite3.connect("students.db")
cursor = conn.cursor()

try:
	cursor.execute("ALTER TABLE students ADD COLUMN grade INTEGER")
	conn.commit()
	print("Modificata tabella degli studenti.")

except sqlite3.OperationalError as e:
	print(e)

