# file esercizio2.py

from __future__ import print_function
from sys import stdout
from os import linesep

def s(n):
	return n + 1

for i in range(10):
	print(s(i), end=" ")

stdout.write(linesep)

