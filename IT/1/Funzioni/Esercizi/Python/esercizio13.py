# file esercizio13.py

from __future__ import print_function

def square(n):
	return n * n

for n in range(1, 11):
	print("{} al quadrato = {}".format(n, square(n)))

