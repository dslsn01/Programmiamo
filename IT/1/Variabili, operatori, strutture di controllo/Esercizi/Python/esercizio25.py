# file esercizio25.py

from __future__ import print_function

if hasattr(__builtins__, 'raw_input'): input = raw_input

s = input("Scrivi un numero: ")

if not s.isdigit() and not s.replace(".", "").isdigit():
	print("Numero non valido!")
	exit()

x = float(s)

xv = x if x >= 0 else -x

print("Valore assoluto di {} = {}".format(x, xv))

