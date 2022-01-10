# file esercizio15.py

from __future__ import print_function
from sys import stdout
from os import linesep

try:
	doc = open("file.txt", "r")

	for line in doc:
		print("{} ".format(line.rstrip()), end="")

	stdout.write(linesep)
	doc.close()

except IOError as e:
	print(e)

