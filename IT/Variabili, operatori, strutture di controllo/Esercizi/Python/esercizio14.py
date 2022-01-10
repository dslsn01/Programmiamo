# file esercizio14.py

from __future__ import print_function
from sys import stdout
from os import linesep

a = 100

print("Divisori di {}:".format(a), end=" ")

for i in range(2, a):
	if a % i == 0:
		print(i, end=" ")

stdout.write(linesep)

