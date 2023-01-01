# file esercizio18.py
# -*- coding: utf-8 -*-

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input

def factorial(n):
	if n == 0 or n == 1:
		return 1
	else:
		return n * factorial(n-1)

s = input("Inserisci un numero intero compreso tra zero e 20: ")

try:
	f = float(s)

	if f < 0 or not f.is_integer():
		raise ValueError("Errore di dominio matematico: fattoriale definito solo per i numeri naturali!")

	n = int(s)

	fact = factorial(n)

	print("{}! = {}".format(n, fact))

except ValueError as e:
	print(e)

print("Fine del programma.")

