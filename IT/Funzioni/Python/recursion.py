# file recursion.py

from __future__ import print_function

if hasattr(__builtins__, 'raw_input'): input = raw_input

def factorial(n):
	if n <= 1: return 1
	else: return n * factorial(n-1)

s = input("Inserisci un numero intero compreso tra zero e 20: ")

if not s.isdigit():
	print("Numero non valido!")
	exit()

n = int(s)

if n > 20:
	print("Numero fuori dell'intervallo!")
	exit()

fact = factorial(n)

print("{}! = {}".format(n, fact))

