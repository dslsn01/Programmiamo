# file esercizio12.py

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input
from os import linesep

print("Scrivi una serie di parole. Invia la stringa vuota per uscire.")

doc = open("file.txt", "w")

while (True):
	s = input("Scrivi una parola: ")

	if not s:
		break

	doc.write(s + linesep)

doc.close()

print("File \"{}\" salvato su disco.".format(doc.name))

