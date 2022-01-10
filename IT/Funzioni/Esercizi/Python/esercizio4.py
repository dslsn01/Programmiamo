# file esercizio4.py

from __future__ import print_function
from sys import stdout
from os import linesep

def abs(n):
	return n if n >= 0 else -n

for i in range (-7, 8):
	print(abs(i), end=" ")

stdout.write(linesep)

