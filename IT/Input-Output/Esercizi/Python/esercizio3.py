# file esercizio3.py

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input

filename = input("Apri il file: ")

try:
	f = open(filename)
	print(f)

except IOError as e:
	print(e)

