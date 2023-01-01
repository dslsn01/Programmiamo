# file testDatabase.py

from __future__ import print_function
import sqlite3

# crea una connessione al database

conn = sqlite3.connect("test.db")

# crea un cursore per esplorare il database 

cursor = conn.cursor()

# crea la nuova tabella dei fumettisti

cursor.execute("CREATE TABLE IF NOT EXISTS cartoonists (id INTEGER PRIMARY KEY, name VARCHAR NOT NULL, surname VARCHAR NOT NULL, CHECK(LENGTH(name) <= 256), CHECK(LENGTH(surname) <= 256))")

# svuota la tabella creata in precedenza: solo a scopo d'esempio!

cursor.execute("DELETE FROM cartoonists")

# aggiunge tre righe alla tabella dei fumettisti

cursor.execute("INSERT INTO cartoonists (name, surname) VALUES ('Walt', 'Disney')")
cursor.execute("INSERT INTO cartoonists (name, surname) VALUES ('Carl', 'Barks')")
cursor.execute("INSERT INTO cartoonists (name, surname) VALUES ('Reg', 'Smythe')")

conn.commit()

# seleziona tutti i fumettisti

cursor.execute("SELECT * FROM cartoonists")

# stampa le righe lette dalla tabella

print(cursor.fetchall())

