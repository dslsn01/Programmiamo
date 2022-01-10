# file esercizio10.py

from __future__ import print_function
from sys import stdout
from os import linesep

i = 1

while i <= 100:
	if i % 2 == 0:
		print(i, end=" ")
	i += 1

stdout.write(linesep)

