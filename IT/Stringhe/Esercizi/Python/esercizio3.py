# file esercizio3.py

from sys import stdout
from os import linesep

s = "Ciao, mondo!"
l = len(s)

for i in range(l):
	stdout.write("(" + str(i) + ") = '" + s[i] + "'")
	# aggiungo la virgola fino al penultimo carattere
	if (i < l-1): stdout.write(", ")

stdout.write(linesep)

