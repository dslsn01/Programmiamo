# file exceptionHandling.py

from __future__ import print_function

n = 5
d = 0

# inizio del blocco try ... except

try:
	q = n / d
	print(q)

except ZeroDivisionError:
	# la clausola except cattura l'eccezione
	print("Divisione per zero!")

print("Fine del programma.")

