# file esercizio16.py

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input

print("Divisione tra numeri interi")

try:
	a = int(input("Dividendo: "))
	b = int(input("Divisore: "))

	if a == 0 and b == 0:
		raise ValueError("Operazione non definita!")

	result = float(a) / b

	print("{} / {} = {}".format(a, b, result))

except ValueError as e:
	print(e)
except ZeroDivisionError as e:
	print(e)

print("Fine del programma.")

