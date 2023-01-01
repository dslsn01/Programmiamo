# file esercizio29.py

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input
from os import path
from sys import stdin, argv

print("Un semplice editor di testo\nPremi \"Ctrl+C\" (su Windows) o \"Ctrl+D\" (Linux e MacOS) per finire di scrivere.\n")

doc = None

if len(argv) > 1:
	filename = argv[1]
	if path.isfile(filename):
		doc = open(filename, "r+")
		for line in doc:
			print(line, end="")
	else:
		doc = open(filename, "w")

text = stdin.readlines()

quit = False

while not quit:
	s = input("Digita \"s\" per salvare su file, \"q\" per uscire senza salvare: ")
	if s.lower() == "s":
		if not doc:
			save = False
			while not save:
				filename = input("Salva con nome: ")
				if path.isfile(filename):
					ow = input("Il file \"" + filename + "\" esiste. Sovrascriverlo? \"y\" - si, \"n\" - no: ")

				if ow.lower() == "y":
					save = True
			else:
				save = True

			doc = open(filename, "w")

		for line in text:
			doc.write(line)

		doc.close()

		print("File \"{}\" salvato su disco.".format(filename))
		quit = True

	elif s.lower() == "q":
		quit = True

