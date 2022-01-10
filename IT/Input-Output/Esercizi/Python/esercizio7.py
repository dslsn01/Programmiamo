# file esercizio7.py

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input

filename = input("Apri il file: ")

try:
	f = open(filename)
	for line in f:
		print(line, end="")

	print("-> torna alla prima riga.")

	# torna all'inizio del file

	f.seek(0)

	for line in f:
		print(line, end="")

except IOError as e:
	print(e)

