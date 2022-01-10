# file esercizio2.py

from __future__ import print_function
from sys import stdout
from os import linesep

li = ["United", "States", "", "America"]

for s in li:
	try:
		print(s[0], end="")
	except IndexError:
		pass

stdout.write(linesep)
print("Fine del programma.")

