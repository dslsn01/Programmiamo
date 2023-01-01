# file esercizio8.py

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input

s = input("Scrivi un numero: ")

try:
	n = int(s)
	print("{} al quadrato = {}".format(n, n * n))

except ValueError as e:
	print(e)

print("Fine del programma.")

