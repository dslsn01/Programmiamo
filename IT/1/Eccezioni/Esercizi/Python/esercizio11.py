# file esercizio11.py

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input
from math import pow

c = 0

while c == 0:
	s = input("Scrivi un numero: ")

	try:
		n = int(s)

		if n == 0:
			raise ValueError("Errore di dominio matematico: radice cubica di zero non definita")

		if n < 0:
			c = -(-n) ** (1./3.)
		else: 
			c = n ** (1./3.)

		print("Radice cubica di {} = {}".format(n, c))

	except ValueError as e:
		print(e)

print("Fine del programma.")

