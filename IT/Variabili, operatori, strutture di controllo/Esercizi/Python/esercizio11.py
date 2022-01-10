# file esercizio11.py

from __future__ import print_function
from sys import stdout
from os import linesep

for i in range(1, 101):
	if i % 5 == 0:
		print(i, end=" ")

stdout.write(linesep)

