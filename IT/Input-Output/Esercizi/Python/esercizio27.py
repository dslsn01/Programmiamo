# file esercizio27.py

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input
from sys import stdin

print("Un semplice editor di testo\nPremi \"Ctrl+C\" (su Windows) o \"Ctrl+D\" (Linux e MacOS) per finire di scrivere.\n")

text = stdin.readlines()

quit = False

while not quit:
	s = input("Digita \"s\" per salvare su file, \"q\" per uscire senza salvare: ")
	if s.lower() == "s":
		filename = input("Salva con nome: ")
		doc = open(filename, "w")

		for line in text:
			doc.write(line)

		doc.close()

		print("File \"{}\" salvato su disco.".format(filename))
		quit = True

	elif s.lower() == "q":
		quit = True

