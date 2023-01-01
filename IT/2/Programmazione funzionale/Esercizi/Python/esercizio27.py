# file esercizio27.py

from __future__ import print_function
from sys import stdout
from os import linesep

def forn(n):
	if n > 0:
		forn(n-1)
		print(n, end=" ")

forn(10)
stdout.write(linesep)

