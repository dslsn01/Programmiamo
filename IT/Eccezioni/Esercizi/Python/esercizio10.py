# file esercizio10.py

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input
from math import sqrt

sq = -1

while (sq < 0):
	s = input("Scrivi un numero: ")

	try:
		n = int(s)
		sq = sqrt(n)
		print("Radice quadrata di {} = {}".format(n, sq))

	except ValueError as e:
		print(e)

print("Fine del programma.")

