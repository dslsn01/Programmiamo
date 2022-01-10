# file esercizio3.py

from __future__ import print_function
from sys import stdout
from os import linesep

var = "Cantami, o Diva, del pelide Achille l'ira funesta"

try:
	i = 0
	while (True):
		print(var[i], end="")
		i += 1

except IndexError:
	stdout.write(linesep)

print("Fine del programma.")

