# file esercizio23.py

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input

filename = input("Apri il file: ")

try:
	doc = open(filename, "r")
	s = input("Parola da cercare: ")
	found = False

	for line in doc:
		if line.lower().find(s.lower()) != -1:
			found = True
			break

	if found:
		print("Parola \"{}\" presente nel file.".format(s))
	else:
		print("Parola \"{}\" non trovata!".format(s))

	doc.close()

except IOError as e:
	print(e)

