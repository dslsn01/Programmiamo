# file esercizio27.py

from __future__ import print_function
from math import sqrt
from sys import stdout
from os import linesep

def pFact(n, f, fact):
	if n < 2: return
	if n % f == 0:
		pFact(n/f, f, fact)
		fact.append(f)
	else:
		f += 1
		pFact(n, f, fact)

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

