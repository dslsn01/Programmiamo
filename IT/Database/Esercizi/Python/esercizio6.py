# file esercizio6.py

from __future__ import print_function
import sqlite3

conn = sqlite3.connect("students.db")
cursor = conn.cursor()

try:
	cursor.execute("CREATE TABLE students (id INTEGER PRIMARY KEY, number VARCHAR UNIQUE NOT NULL, name VARCHAR NOT NULL, surname VARCHAR NOT NULL, age INTEGER, CHECK(LENGTH(number) == 6), CHECK(LENGTH(name) <= 255), CHECK(LENGTH(surname) <= 255))")
	conn.commit()
	print("Creata tabella degli studenti.")

except sqlite3.OperationalError as e:
	print(e)

