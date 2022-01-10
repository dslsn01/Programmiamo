# file testList1.py
# -*- coding: utf-8 -*-

from __future__ import print_function

# dichiara una lista di stringhe

li = ["tigre", "giraffa", "elefante"]
print(li)

# verifica la presenza dell'"elefante" nella lista, se presente stampa la sua posizione

if "elefante" in li:
	index = li.index("elefante")
	print("Nella lista degli animali c'è un elefante alla posizione {}.".format(index))

# modifica il secondo elemento in lista da "giraffa" a "cane"

print("Sostituisco la giraffa con un cane.")
li[1] = "cane"
print(li)

# in Python possiamo aggiungere e togliere elementi da una lista in qualsiasi momento

print("Aggiungo una balenottera azzurra.")
li.append("balenottera")

print("La lista contiene {} elementi.".format(len(li)))

# itera attraverso la lista con un ciclo for

for i in range(len(li)):
	print("{}) {}".format(i, li[i]))

print("Rimuovo il cane.")
li.remove("cane")

# itera attraverso la lista con un ciclo foreach

for e in li:
	print(e)

print("La lista contiene {} elementi.".format(len(li)))

