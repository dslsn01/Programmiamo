# file esercizio4.py

from sys import stdout
from os import linesep

s = "Ciao, mondo!"

for i in range(len(s) -1, -1, -1):
	c = s[i]
	stdout.write(c)

stdout.write(linesep)

