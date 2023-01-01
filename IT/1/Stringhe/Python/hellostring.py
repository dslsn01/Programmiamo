# file hellostring.py

from __future__ import print_function, unicode_literals
from sys import stdout
from os import linesep

# dichiara una stringa di caratteri

s = "Ciao, mondo!"

# stampa la stringa sulla console, carattere per carattere

for c in s:
	stdout.write(c)

# aggiunge un'interruzione di riga

stdout.write(linesep)

