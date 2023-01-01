# file esercizio18.py

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input
from os import path, linesep

filename = input("File su cui scrivere: ")

if path.isfile(filename):
	print("Il file esiste. Le modifiche saranno aggiunte al file esistente.")
	doc = open(filename, "a")
else:
	doc = open(filename, "w")

print("Scrivi una serie di parole. Invia la stringa vuota per uscire.")

while (True):
	s = input("Scrivi una parola: ")

	if not s:
		break

	doc.write(s + linesep)

doc.close()

print("File \"{}\" salvato su disco.".format(doc.name))

