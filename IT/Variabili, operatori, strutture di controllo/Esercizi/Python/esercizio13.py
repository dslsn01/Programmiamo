# file esercizio13.py

from __future__ import print_function
from sys import stdout
from os import linesep

a = 10

print("a =", a, end=" ")

while a > 0:
	a -= 2
	print(a, end=" ")

stdout.write(linesep)

