# file passByValue.py

from __future__ import print_function

def square(n):
	n = n * n
	return n

n = 2

print("Valore di n (prima):", n)

# reimposta la variabile originale

n = square(n)

print("Valore di n (dopo):", n)

