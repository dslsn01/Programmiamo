# file esercizio22.py

from __future__ import print_function

if hasattr(__builtins__, 'raw_input'): input = raw_input

s = input("Scrivi un numero: ")

if not s.isdigit():
	print("Numero non valido!")
	exit()

n = int(s)

q = n * n

print("{} al quadrato = {}".format(n, q))

