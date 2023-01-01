# file esercizio1.py

from __future__ import print_function
import sqlite3

conn = sqlite3.connect("students.db")
cursor = conn.cursor()

try:
	cursor.execute("CREATE TABLE students (id INTEGER PRIMARY KEY, number VARCHAR, name VARCHAR, surname VARCHAR, age INTEGER)")
	conn.commit()
	print("Creata tabella degli studenti.")

except sqlite3.OperationalError as e:
	print(e)

