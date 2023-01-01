# file esercizio24.py

from __future__ import print_function

if hasattr(__builtins__, 'raw_input'): input = raw_input

s = input("Scrivi un numero: ")

if not s.isdigit():
	print("Numero non valido!")
	exit()

n = int(s)

ex = 2
while (ex <= 10):
	print("Potenza di {} elevato a {} = {}".format(n, ex, n**ex))
	ex += 1

