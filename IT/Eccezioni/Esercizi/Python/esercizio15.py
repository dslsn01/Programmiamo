# file esercizio15.py
# -*- coding: utf-8 -*-

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input

print("Pari o dispari?")

s = input("Scrivi un numero: ")

try:
	if not float(s).is_integer():
		raise ValueError("Errore di dominio matematico: la distinzione tra \"pari\" o \"dispari\" vale solo per i numeri interi!")

	n = int(s)
	if n % 2 == 0:
		print("{} è pari!".format(n))
	else:
		print("{} è dispari!".format(n))

except ValueError as e:
	print(e)

print("Fine del programma.")

