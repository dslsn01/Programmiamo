# file esercizio13.py

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input
from math import log

l = -1

while (l < 0):
	s = input("Scrivi un numero: ")

	try:
		n = int(s)
		l = log(n)
		print("Logaritmo di {} = {}".format(n, l))

	except ValueError as e:
		print(e)

print("Fine del programma.")

