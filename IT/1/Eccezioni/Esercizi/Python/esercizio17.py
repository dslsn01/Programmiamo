# file esercizio17.py

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input

def divide(a, b):
	if a == 0 and b == 0:
		raise ValueError("Operazione non definita!")

	return float(a) / b

print("Divisione tra numeri interi")

try:
	a = int(input("Dividendo: "))
	b = int(input("Divisore: "))

	if a == 0 and b == 0:
		raise ValueError("Operazione non definita!")

	result = divide(a, b)

	print("{} / {} = {}".format(a, b, result))

except ValueError as e:
	print("Inserito un numero non valido!", e)

except ZeroDivisionError as e:
	print("Divisione per zero!", e)

print("Fine del programma.")

