# file testTransaction.py
# -*- coding: utf-8 -*-

from __future__ import print_function
from datetime import date, timedelta
import sqlite3

conn = sqlite3.connect("list.db", detect_types=sqlite3.PARSE_DECLTYPES | sqlite3.PARSE_COLNAMES)
# abilita le foreign key
conn.execute("PRAGMA foreign_keys=ON;")
cursor = conn.cursor()

# crea tabella dei pazienti, lista d'attesa e degli interventi programmati

cursor.execute("CREATE TABLE IF NOT EXISTS patients (name VARCHAR NOT NULL, surname VARCHAR NOT NULL, PRIMARY KEY(name, surname), CHECK(LENGTH(name) <= 256), CHECK(LENGTH(surname) <= 256))")
cursor.execute("CREATE TABLE IF NOT EXISTS wtList (name VARCHAR, surname VARCHAR, r_date DATE NOT NULL, FOREIGN KEY(name, surname) REFERENCES patients(name, surname) ON DELETE CASCADE)")
cursor.execute("CREATE TABLE IF NOT EXISTS interv (name VARCHAR, surname VARCHAR, sched DATE NOT NULL, desc VARCHAR, CHECK(LENGTH(desc) <= 256), FOREIGN KEY(name, surname) REFERENCES patients(name, surname) ON DELETE CASCADE)")

# svuota tutt'e tre le tabelle (solo a scopo di test!)

cursor.execute("DELETE FROM patients")
cursor.execute("DELETE FROM wtList")
cursor.execute("DELETE FROM interv")

# salva i nominativi di tre pazienti

cursor.execute("INSERT INTO patients (name, surname) VALUES ('Giovanni', 'Verdi')")
cursor.execute("INSERT INTO patients (name, surname) VALUES ('Giuseppe', 'Bianchi')")
cursor.execute("INSERT INTO patients (name, surname) VALUES ('Luigi', 'Rossi')")

# inserisce due pazienti in lista d'attesa in modo casuale

cursor.execute("INSERT INTO wtList (name, surname, r_date) SELECT name, surname, DATE('now') FROM patients ORDER BY RANDOM() LIMIT 2")

# fine prima transazione

conn.commit()

res = cursor.execute("SELECT name, surname, r_date FROM wtList LIMIT 1")
p = res.fetchone()
name = p[0]
surname = p[1]
r_date = p[2]

print("Il paziente {} {} è in lista d'attesa dal {}.".format(name, surname, r_date.strftime("%d/%m/%Y")))

# inserisce un paziente nella lista degli interventi programmati, rimuovendolo dalla lista d'attesa

pStmt = "INSERT INTO interv (name, surname, sched, desc) VALUES (?, ?, ?, ?)"
i_date = r_date + timedelta(days=3)

cursor.execute(pStmt, (name, surname, i_date, "endodonzia"))

pStmt = "DELETE FROM wtList WHERE name = ? AND surname = ?"
cursor.execute(pStmt, (name, surname))

# fine seconda transazione

conn.commit()

print("{} {} sarà sottoposto a intervento il giorno {}.".format(name, surname, i_date.strftime("%d/%m/%Y")))

