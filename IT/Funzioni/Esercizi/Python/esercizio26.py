# file esercizio26.py

from __future__ import print_function
from math import sqrt
from sys import stdout
from os import linesep

def pFact(n, f, fact):
	if i <= 3: return
	m = n
	sr = sqrt(n)
	for f in range(2, int(sr)+1):
		while m % f == 0:
			fact.append(f)
			m = m / f
	if (m > 1): fact.append(m)

for i in range(4, 20):
	fact = []
	pFact(i, 2, fact)
	print("{} = ".format(i), end="")
	l = len(fact)
	if l > 1:
		for j in range(l):
			p = fact[j]
			print(p, end="")
			if j < l-1: print(" * ", end="")
			else: stdout.write(linesep)
	else:
		print("primo.")

