# file testDict.py

from __future__ import print_function
from sys import stdout
from os import linesep

# crea un dizionario che contiene tre coppie chiave-valore

_dict = {"nome":"John", "cognome":"Doe", "anni":"30"}
print(_dict)

# verifica la presenza della chiave "nome" nel dizionario, e stampa il valore corrente 

if "nome" in _dict:
	print("Valore della chiave \"nome\":", _dict["nome"])

# modifica e stampa il valore associato alla chiave "nome" del dizionario

_dict["nome"] = "Steve"
print("Nuovo valore della chiave \"nome\":", _dict["nome"])

# aggiunge una nuova coppia chiave-valore al dizionario

_dict["stato civile"] = "sposato"

print("Aggiunto stato civile.")
print("Stampo le coppie chiave-valore.")

for k in _dict.keys():
	print("'{}': '{}'".format(k, _dict[k]), end=" ")

stdout.write(linesep)

# rimuove una coppia chiave-valore dal dizionario

del _dict["stato civile"]
print("Stato civile rimosso.")
print(_dict)

