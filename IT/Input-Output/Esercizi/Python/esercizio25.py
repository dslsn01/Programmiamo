# file esercizio25.py

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input

filename = input("Apri il file: ")

try:
	doc = open(filename, "r")
	s = input("Parola da cercare: ")
	found = False
	i = 1

	for line in doc:
		if line.lower().find(s.lower()) != -1:
			if not found: found = True
			print("La parola \"{}\" compare alla riga {}.".format(s, i))
		i = i + 1

	if not found:
		print("Parola \"{}\" non trovata!".format(s))

	doc.close()

except IOError as e:
	print(e)

