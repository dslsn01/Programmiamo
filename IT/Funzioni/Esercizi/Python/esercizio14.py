# file esercizio14.py

from __future__ import print_function

def cube(n):
	return n * n * n

for n in range(1, 11):
	print("{} al cubo = {}".format(n, cube(n)))

