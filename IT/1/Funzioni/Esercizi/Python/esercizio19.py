# file esercizio19.py

from __future__ import print_function
from math import sqrt
from sys import stdout
from os import linesep

def prime(n):
	if n <= 1: return False
	if n in (2, 3): return True
	sr = sqrt(n)
	for i in range(2, int(sr)+1):
		if n % i == 0: return False
	return True

for n in range(2, 101):
	if prime(n) == True:
		print(n, end=" ")

stdout.write(linesep)

