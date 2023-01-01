# file esercizio24.py

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input

filename = input("Apri il file: ")

try:
	doc = open(filename, "r")
	s = input("Parola da cercare: ")
	counter = 0

	for line in doc:
		counter += line.lower().count(s.lower())

	if counter != 0:
		print("La parola \"{}\" compare {} volte nel file.".format(s, counter))
	else:
		print("Parola \"{}\" non trovata!".format(s))

	doc.close()

except IOError as e:
	print(e)

