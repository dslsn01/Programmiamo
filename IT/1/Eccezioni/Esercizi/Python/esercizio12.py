# file esercizio12.py

from __future__ import print_function
if hasattr(__builtins__, 'raw_input'): input = raw_input

r = 0

while r == 0:
	s = input("Scrivi un numero: ")

	try:
		n = int(s)
		r = float(1)/n
		print("Reciproco di {} = {}".format(n, r))

	except ZeroDivisionError as e:
		print(e)
	except ValueError as e:
		print(e)

print("Fine del programma.")

